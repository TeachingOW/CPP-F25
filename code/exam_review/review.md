

#P 3

#include <vector>
class BitVector : public std::vector<unsigned char> {
	size_t no_of_bits = 0;


public:
	BitVector() :no_of_bits{ 0 } {};
	
	// Pushes a single bit (0 or 1) to the back of the vector
	void push_back(bool bit) {
		if (no_of_bits % 8 == 0) {
				//need to add a new byte
			std::vector<unsigned char>::push_back(0);
		}
		if (bit) {
			unsigned char& v = std::vector<unsigned char>::operator [](no_of_bits / 8);
			v |= 1 << (no_of_bits % 8);
		}
		no_of_bits++;
	}
	// Returns the number of bits stored in the BitVector
	size_t size() const  {
		return no_of_bits;
	}
	// Accesses a specific bit by index (0-based)
	bool operator[](int index) const {
		 unsigned char v = std::vector<unsigned char>::operator [](index / 8);
		return ( v & (1 << (index % 8)));
	}
};


#P 4
```c++
int get_bucket(double v, double min_, double max_,int num){
	double w= (max_-min_) /num;
	auto b=	(int)((v-min_ )/w);
	if(b==num) b--;
	return b;
}
std::vector<int> build_histogram_with_buckets(const std::vector<double>&
data, int num_buckets) {

	vector<int> buckets(num_buckets,0);
	cassert(data.size()>1);
	double min_=data[0];
	for(int i=0;i<data.size();i++)
		min_=std::min(min_,data[i]);
	// or
	//auto min_=min_element(data.begin(), data.end());
	auto max_=max_element(data.begin(), data.end());
	
	for(auto v: data){
		int b=get_bucket(v,min_,max_,num_buckets);
		buckets[b]++;
	}

	return buckets;

}
```
# P 5
```c++
double dot_product_normalized(const std::vector<double>& vec1, const std::vector<double>& vec2) {

	double mag1=0;
	for(int i=0;i<vec1.size();i++){
		mag1+=vec1[i]*vec1[i]; 
	}

	double mag2=0;
	for(auto v :v2) {
		mag2+=v*v;
	}
	
	mag1=sqrt(mag1);
	mag2=pow(mag2,0.5);
	
	double sum=0;
	for(int i=0;i<vec1.size();i++){
		sum+=vec1[i]*vec2[i];
	}
	
	return sum/mag1/mag2;
}
```
