#include <iostream>
#include <fstream>
#include <format>
#include <cstring>
#include <string>
#include <cctype>

void decodeBinary(char* arg){
	std::cout << "Encoding binary...\n";
	char size = ( (strlen(arg))/6 ) + ( ((strlen(arg))%6) != 0 );
	char* out = new char[size]{};
	for(int i = 0, j = 0; arg[i] != '\0'; ++j, i += 6){
		if( ((arg[i+0] >= '0') && (arg[i+0] <= '1')) ){
			out[j]  = (arg[i+0] - '0') << 5;
		}else if(arg[i+0] == '\0'){
			out[j]  = (arg[i+0] - '0') << 5;
			break;
		}else{
			std::cout << std::format("not a binary number: {}\n", arg[i+0]);
			break;
		}
		if( ((arg[i+1] >= '0') && (arg[i+1] <= '1')) ){
			out[j] ^= (arg[i+1] - '0') << 4;
		}else if(arg[i+1] == '\0'){
			out[j] ^= (arg[i+1] - '0') << 4;
			break;
		}else{
			std::cout << std::format("not a binary number: {}\n", arg[i+1]);
			break;
		}
		if( ((arg[i+2] >= '0') && (arg[i+2] <= '1')) ){
			out[j] ^= (arg[i+2] - '0') << 3;
		}else if(arg[i+2] == '\0'){
			out[j] ^= (arg[i+2] - '0') << 3;
			break;
		}else{
			std::cout << std::format("not a binary number: {}\n", arg[i+2]);
			break;
		}
		if( ((arg[i+3] >= '0') && (arg[i+3] <= '1')) ){
			out[j] ^= (arg[i+3] - '0') << 2;
		}else if(arg[i+3] == '\0'){
			out[j] ^= (arg[i+3] - '0') << 2;
			break;
		}else{
			std::cout << std::format("not a binary number: {}\n", arg[i+3]);
			break;
		}
		if( ((arg[i+4] >= '0') && (arg[i+4] <= '1')) ){
			out[j] ^= (arg[i+4] - '0') << 1;
		}else if(arg[i+4] == '\0'){
			out[j] ^= (arg[i+4] - '0') << 1;
			break;
		}else{
			std::cout << std::format("not a binary number: {}\n", arg[i+4]);
			break;
		}
		if( ((arg[i+5] >= '0') && (arg[i+5] <= '1')) ){
			out[j] ^= (arg[i+5] - '0') << 0;
		}else if(arg[i+5] == '\0'){
			out[j] ^= (arg[i+5] - '0') << 0;
			break;
		}else{
			std::cout << std::format("not a binary number: {}\n", arg[i+5]);
			break;
		}
	}
	std::ofstream ppFile("pp.hex", std::ios::binary | std::ios::out);
	ppFile.write(out, size);
	ppFile.close();
}

int main(int argc, char* argv[]){
	if(argc < 2){
		std::cout << std::format("Usage: {} <-b> <argument>\n", argv[0]);
		return 0;
	}
	if(!strcmp(argv[1], "-b")){
		if(argv[2] == NULL){
			std::cout << "missing argument.\n";
			std::cout << std::format("Usage: {} -b <argument>\n", argv[0]);
			return 0;
		}
		decodeBinary(argv[2]);
		return 0;
	}else{
		std::cout << std::format("Usage: {} <-b> <argument>\n", argv[0]);
		return 1;
	}
	return 0;
}
