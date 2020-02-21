// Muhammad Adil Zafar Khan
// V00924050
// 09/13/19
// The code takes in a series of alphabets, a message and a key and encrypts and decrypts the message.
// It outputs both the encrypted and decrypted message. 

#include<iostream>
#include<string>
#include<vector>

int main(){
    std::string alpha{};
    std::string msg{};
    std::string key{};
    std::string realkey{};
    std::vector<int> index {};
    std::vector<int> index2 {};
    std::vector<int> sum {};
    std::vector<int> difference {};
    std::getline(std::cin,alpha);
    std::getline(std::cin,msg);
    std::getline(std::cin,key);
    realkey = key;
    int z{};
    int msgsize = msg.size();
    int alphasize = alpha.size();
    int keysize = key.size();
    std::string encrypted{};
    std::string decrypted{};

    
    for (int x = 0; x < (msgsize - keysize); x++){
        key.push_back(key.at(z));
        z++;
        if (z >= keysize){
            z = 0;
        }
    }
    for(unsigned int x = 0; x < msg.size(); x++){
        for (unsigned int y = 0; y < alpha.size(); y++){
            if (msg[x]==alpha[y]){
                index.push_back(y);
            }
        }
    }
    for(unsigned int x = 0; x < key.size(); x++){
        for (unsigned int y = 0; y < alpha.size(); y++){
            if (key[x]==alpha[y]){
                index2.push_back(y);
            }
        }
    }

    for(unsigned int c = 0; c < msg.size(); c++){
        sum.push_back(index.at(c) + index2.at(c));
        if (sum.at(c) >= alphasize){
            sum.at(c) = sum.at(c) - alphasize;
        }
    }

    for (int val : sum){
        encrypted.push_back(alpha.at(val));
    }

    for(unsigned int c = 0; c < msg.size(); c++){
        difference.push_back(index.at(c) - index2.at(c));
        if (difference.at(c) < 0){
            difference.at(c) = alpha.size() + difference.at(c);
        }
    }
    for (int val : difference){
        decrypted.push_back(alpha.at(val));
    }

    std::cout << std::endl;
    std::cout << "Alphabet: [" << alpha << "]" << std::endl;
    std::cout << "Message: [" << msg << "]" << std::endl;
    std::cout << "Key: [" << realkey << "]" << std::endl;
    std::cout << "Encrypted: [" << encrypted << "]" << std::endl;
    std::cout << "Decrypted: [" << decrypted << "]" << std::endl;

    return 0;
    
}





