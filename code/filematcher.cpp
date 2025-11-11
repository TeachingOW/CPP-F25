#include <iostream>
#include <filesystem>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <fstream>
using namespace std;


class FileDiscovery {
public:
    static vector<string> find(vector<string> paths) {
        set<string> out;
        for(auto path:paths)
        for (const auto& entry : filesystem::recursive_directory_iterator(path)) {
            try {
                if (entry.is_regular_file()) //-- what else to add
                    out.insert(entry.path().string());
               
            }
            catch (...) {

            }
                
        }
        return vector<string>(out.begin(), out.end());
    }
};
class FileHash {
public:
    static  unsigned long simple_file_hash(const std::string& file_path) {
        std::ifstream file(file_path, std::ios::binary);
        if (!file.is_open()) {
            std::cerr << "Failed to open: " << file_path << std::endl;
            return 0;
        }

        unsigned long hash = 5381;  // Starting seed (DJB2 style)
        char c;

        while (file.get(c)) {
            hash = ((hash << 5) + hash) + static_cast<unsigned char>(c); // hash * 33 + c
        }

        return hash;
    }

};

class ht {
public:
    void insert(unsigned int k, string v) {
        if (ht2.find(k) == ht2.end()) {
            // k is not in the hash table
            ht2.insert(make_pair(k, vector<string>{}));
        }
        ht2[k].push_back(v);
    }
    vector<string>& find(unsigned int k) {
        return  ht2[k];
    }
   
    auto begin() {
        return ht2.begin();
    }
    
    auto end() {
        return ht2.end();
    }
private:
    unordered_map <unsigned long, vector<string>> ht2;
};

class FileMatcher {
    
    public:
    static void match(ht h, vector<string> paths) {
        auto file_collections = FileDiscovery::find(paths);
        for (auto f : file_collections) {
            unsigned long hashed = FileHash::simple_file_hash(f);

            cout << f << "\t";
            cout << hashed;
            cout << "\n";
            h.insert(hashed, f);
        }
        //
        for (auto k = h.begin(); k != h.end(); k++) {
            if (k->second.size() > 1) {
                cout << k->first << " \n\n";
                for (auto l : k->second)cout << l;
                cout <<"\t\t\n";
            
            
            }

        }

    }

};
int main() {
    vector<string> p = { "c:\\users\\khalefam\\Downloads\\" };
    ht h;
    FileMatcher::match(h,p);

}
