//
// Created by dbori on 10.05.2023.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#define DATA_F_NAME "ccr-cca.gy.csv"
#define LINES_COUNT 100000

int main(int argc, char **argv) {
	std::ofstream output(DATA_F_NAME, std::ios::trunc);
	auto base_msisdn = 525579325639;
	auto base_imsi = 334020428795056;
	auto base_framed_ip = 0x0ade2dc1;
	auto base_imeisv = 8614750302159801;
	output << "\"string\";\"string\";\"string\";\"string\";" << std::endl;
	output << "#\"e164\";\"imsi\";\"framed ip\";\"imeisv\";" << std::endl;
	for (auto i = 0; i < LINES_COUNT; ++i) {
		output << std::setfill('0') << "\"" <<
		       std::setw(12) << std::dec << base_msisdn << "\";\"" <<
		       std::setw(15) << std::dec << base_imsi << "\";\"" <<
		       "0x" << std::setw(8) << std::hex << base_framed_ip << "\";\"" <<
		       std::setw(16) << std::dec << base_imeisv << "\";" << std::endl;
		base_msisdn++;
		base_imsi++;
		base_framed_ip++;
		base_imeisv += 100;
	}
}