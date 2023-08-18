#include "mySolution.h" 
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include <utility>
#include <iterator>
#include <cctype>

using namespace std;

std::string look_up_table{ "aeiou" };

int solve(const std::string& s)
{
    int count{ 0 };
    int count1{ 0 };

    for (auto i = s.begin(); i != s.end(); i++) {
        auto j = i;
       
        while (i != s.end() && look_up_table.find(*i) == std::string::npos) 
            ++i;
        
        count1 = accumulate(j, i,0, [](int x, int y) {return x + (y - 96); });
      
        if (count1 > count) 
            count = count1;
        
      
        if (i == s.end())
            return count;
    }

    return count;
}



bool valid_braces(std::string braces)
{
    if (braces.empty()) return true;

    stack<char> val;

    for (auto iter = braces.begin(); iter < braces.end(); ++iter) {
        if (*iter == '(' || *iter == '[' || *iter == '{') {
            val.push(*iter);
        }
        else if (*iter == ']' || *iter == '}') {
            if (val.empty() || (val.top() != (*iter - 2)))
                return false;
            val.pop();
        }
        else {
            if (val.empty() || val.top() != (*iter - 1))
                return false;
            val.pop();
        }
    }
    return true;
}


std::vector<int> move_zeroes(const std::vector<int>& input) {
    vector<int> vec;

    copy(input.begin(), input.end(), back_inserter(vec));

    auto iter = remove_if(vec.begin(), vec.end(), [](vector<int>::value_type x) { return x == 0; });
  while(iter != vec.end())
    *iter++ = 0;

    return vec;
}


bool isPrime(int n)
{
    if (n == 2 || n == 3)
        return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

class GapInPrimes
{
public:
    static std::pair<long long, long long> gap(int g, long long m, long long n) {
      pair<long long, long long> my_pair{0,0};
      
      while(m <= n){
        if(isPrime(m)){
          my_pair.second = m;
          if((my_pair.second - my_pair.first == g) && (my_pair.first)) return my_pair;
             else my_pair.first = my_pair.second; 
        } ++m;
      } 
        return {0,0};
  }
friend bool isPrime(long long val);
};


using namespace std;

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {
  pair<size_t,size_t> my_pair{0,0};
  auto sayac{0};
  for(const int& i : numbers){
    for(auto j = numbers.begin() + 1; j != numbers.end(); ++j){
      if((i + *j) == target){
        my_pair.first = sayac;
        my_pair.second = distance(numbers.begin(), j);
        return my_pair;
      }
    }
    ++sayac;
  }
  return my_pair;
}


const char* look_up_table[]{"snake","camel","kebab"};

string changeCase(const string& identifier, const string& targetCase)
{
    string my_string{};
   
  
    if (identifier.find('_') != string::npos) {
        if (targetCase == look_up_table[0]) {
            for (auto iter = identifier.begin(); iter != identifier.end(); ++iter) {
                if (!islower(*iter) && *iter != '_')
                    return "";
            }
            return identifier;
        }
        if (targetCase == look_up_table[1]) {
            for (auto iter = identifier.begin(); iter != identifier.end(); ++iter) {
                if (!islower(*iter)&& *iter != '_')
                    return "";
                if (*iter != '_') {
                    my_string.push_back(*iter);
                }
                else {
                    my_string.push_back(*++iter - 32);
                }
            }
        }
        if (targetCase == look_up_table[2]) {
            for(const char& c : identifier)
                if (!islower(c) && c != '_')
                    return "";
            transform(identifier.begin(), identifier.end(), back_inserter(my_string), [](char c) {if (c == '_') return '-'; return c; });
        }

    }
    else if (identifier.find('-') != string::npos) {
        if (targetCase == look_up_table[2]) {
            for (auto iter = identifier.begin(); iter != identifier.end(); ++iter) {
                if (!islower(*iter) && *iter != '-')
                    return "";
                
            }
            return identifier;
        }
        if (targetCase == look_up_table[0]) {
            for (const char& c : identifier)
                if (!islower(c)  && c != '-')
                    return "";
            transform(identifier.begin(), identifier.end(), back_inserter(my_string), [](char c) {if (c == '-') return '_'; return c; });
        }
        if (targetCase == look_up_table[1])
            for (auto iter = identifier.begin(); iter != identifier.end(); ++iter) {
                if (!(islower(*iter)) && *iter != '-')
                    return "";
                if (*iter != '-') {
                    my_string.push_back(*iter);
                }
                else {
                    my_string.push_back(*++iter - 32);
                }
            }
    }
    else {
        if (targetCase == look_up_table[1]) {
            for (auto iter = identifier.begin(); iter != identifier.end(); ++iter) {
                if (!isalpha(*iter))
                    return "";
                
            }
            return identifier;
        }
        for (auto iter = identifier.begin(); iter != identifier.end(); ++iter) {
            if (!(isalpha(*iter)))
                return "";
            if (isupper(*iter)) {
                my_string.push_back('_');
                my_string.push_back(tolower(*iter));
            }else my_string.push_back(*iter);
        }
        if (targetCase == look_up_table[2]) {
            transform(my_string.begin(), my_string.end(), my_string.begin(), [](char c) {if (c == '_') return '-'; return c; });
          
        }

    }
    return my_string;
}