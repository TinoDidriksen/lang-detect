// Copyright 2013 Tino Didriksen, All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <compact_lang_det.h>
#include <encodings.h>
#include <iostream>
#include <vector>
#include <string>
using namespace CLD2;

int main(int argc, char *argv[]) {
	std::vector<std::string> args(argv, argv + argc);
	Language langhint = UNKNOWN_LANGUAGE;

	if (args.size() > 1) {
		if (args[1] == "dan") {
			langhint = DANISH;
		}
		else if (args[1] == "deu") {
			langhint = GERMAN;
		}
		else if (args[1] == "eng") {
			langhint = ENGLISH;
		}
		else if (args[1] == "epo") {
			langhint = ESPERANTO;
		}
		else if (args[1] == "fra") {
			langhint = FRENCH;
		}
		else if (args[1] == "ita") {
			langhint = ITALIAN;
		}
		else if (args[1] == "nor") {
			langhint = NORWEGIAN;
		}
		else if (args[1] == "por") {
			langhint = PORTUGUESE;
		}
		else if (args[1] == "por-BR") {
			langhint = PORTUGUESE;
		}
		else if (args[1] == "spa") {
			langhint = SPANISH;
		}
		else if (args[1] == "swe") {
			langhint = SWEDISH;
		}
	}

	std::string head, body, line;
	while (std::getline(std::cin, line)) {
		// <s lines open chunks
		if (line[0] == '<' && line[1] == 's') {
			head = line;
			continue;
		}
		// Ignore <STYLE and </STYLE lines
		if (line[0] == '<' && line[1] == 'S') {
			continue;
		}
		if (line[0] == '<' && line[1] == '/' && line[2] == 'S') {
			continue;
		}
		// Found a </s line, so process this chunk
		if (line[0] == '<' && line[1] == '/' && line[2] == 's') {
			bool is_plain_text = false;
			const char* tldhint = "";
			const Encoding enchint = UNKNOWN_ENCODING;
			const CLDHints cldhints = { NULL, tldhint, enchint, langhint };
			Language language3[3];
			int percent3[3];
			double normalized_score3[3];
			ResultChunkVector resultchunkvector;
			int text_bytes;
			bool is_reliable;

			Language lang_detected = ExtDetectLanguageSummary(
				body.c_str(),
				body.size(),
				is_plain_text,
				&cldhints,
				0,
				language3,
				percent3,
				normalized_score3,
				NULL,
				&text_bytes,
				&is_reliable);

			if (lang_detected != langhint && lang_detected != UNKNOWN_LANGUAGE) {
				std::cout << head << std::endl;
				for (size_t i = 0; i < 3; ++i) {
					std::cout << LanguageCode(language3[i]) << '\t' << percent3[i] << '\t' << normalized_score3[i] << std::endl;
				}
				std::cout << line << std::endl;
			}

			body.clear();
			continue;
		}
		body += line;
	}
}
