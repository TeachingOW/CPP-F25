#include <iostream>
#include <filesystem>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <optional>
#include <string>

using namespace std;
namespace fs = std::filesystem;

// ---------------------------------------------
//  FileKey: Composite key (file_size + hash)
// ---------------------------------------------
struct FileKey {
    uint64_t size;
    uint64_t hash;

    bool operator==(const FileKey& o) const {
        return size == o.size && hash == o.hash;
    }
};

struct FileKeyHash {
    size_t operator()(const FileKey& k) const noexcept {
        // 64-bit mix (similar to boost::hash_combine)
        uint64_t h = k.hash;
        h ^= k.size + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
        return static_cast<size_t>(h);
    }
};

// ---------------------------------------------
//  File hashing: buffered + DJB2 + xxhash-style mix
// ---------------------------------------------
class FileHash {
public:
    static uint64_t fast_hash(const string& path)
    {
        ifstream file(path, ios::binary);
        if (!file.is_open())
            return 0;

        uint64_t hash = 5381;
        char buffer[4096];

        while (file.read(buffer, sizeof(buffer)) || file.gcount()) {
            size_t n = file.gcount();
            for (size_t i = 0; i < n; i++) {
                hash = ((hash << 5) + hash) + static_cast<unsigned char>(buffer[i]); // DJB2
            }
        }

        // Mix to reduce collisions
        hash ^= (hash >> 33);
        hash *= 0xff51afd7ed558ccdULL;
        hash ^= (hash >> 33);
        hash *= 0xc4ceb9fe1a85ec53ULL;
        hash ^= (hash >> 33);

        return hash;
    }
};

// ---------------------------------------------
//  File discovery
// ---------------------------------------------
class FileDiscovery {
public:
    static vector<string> find(const vector<string>& paths)
    {
        vector<string> out;
        out.reserve(4096);

        for (const auto& p : paths) {
            try {
                for (const auto& entry : fs::recursive_directory_iterator(p)) {
                    if (entry.is_regular_file())
                        out.push_back(entry.path().string());
                }
            }
            catch (const exception& e) {
                cerr << "Error scanning " << p << ": " << e.what() << endl;
            }
        }
        return out;
    }
};

// ---------------------------------------------
//  ht: A clean wrapper over unordered_map
//      ht<Key> : vector<string>
// ---------------------------------------------
template <typename Key, typename Hash = std::hash<Key>>
class ht : public unordered_map<Key, vector<string>, Hash>
{
public:

    // Insert file path under the key
    void insert_value(const Key& k, const string& v)
    {
        (*this)[k].push_back(v);
    }

    
};

// ---------------------------------------------
//  Byte-by-byte exact comparison
// ---------------------------------------------
class FileMatcher {
public:
    static void exact_compare(const vector<string>& paths,
                              vector<pair<string, string>>& matches)
    {
        for (size_t i = 0; i < paths.size(); i++) {
            for (size_t j = i + 1; j < paths.size(); j++) {

                if (fs::file_size(paths[i]) != fs::file_size(paths[j]))
                    continue;

                ifstream f1(paths[i], ios::binary);
                ifstream f2(paths[j], ios::binary);
                if (!f1.is_open() || !f2.is_open())
                    continue;

                istreambuf_iterator<char> b1(f1), e1;
                istreambuf_iterator<char> b2(f2), e2;

                if (equal(b1, e1, b2)) {
                    matches.emplace_back(paths[i], paths[j]);
                }
            }
        }
    }

    static vector<pair<string, string>> find_matches(const vector<string>& paths)
    {
        // Discover files
        auto files = FileDiscovery::find(paths);

        ht<FileKey, FileKeyHash> table;

        // Hash each file
        for (const auto& f : files) {
            uint64_t sz = fs::file_size(f);
            uint64_t h  = FileHash::fast_hash(f);

            FileKey key{ sz, h };
            table.insert_value(key, f);

            cout << "[HASH] " << f << " → size=" << sz << ", hash=" << h << "\n";
        }

        // Compare files inside each bucket
        vector<pair<string, string>> matches;

        for (auto& [key, vec] : table) {
            if (vec.size() > 1)
                exact_compare(vec, matches);
        }

        return matches;
    }
};

// ---------------------------------------------
//  Main
// ---------------------------------------------
int main()
{
    vector<string> paths = { "." };

    auto matches = FileMatcher::find_matches(paths);

    cout << "\n--- EXACT MATCHES ---\n";
    for (auto& m : matches)
        cout << m.first << " <==> " << m.second << "\n";
}
