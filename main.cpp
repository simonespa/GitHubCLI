/**
 * @file main.cpp
 * @author Simone Spaccarotella (spa.simone@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-08-10
 *
 * @copyright
 *
 * GitHub CLI is a command line tool to interface with GitHub.
 * Copyright (C) 2022 Simone Spaccarotella
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <string>
#include <cstring>
#include <curl/curl.h>
#include "CLI11.hpp"

using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  ((std::string *)userp)->append((char *)contents, size * nmemb);
  return size * nmemb;
}

int main(int argc, char** argv) {
  CLI::App app{"The GitHub CLI"};
  // "strdup" returns a pointer to a new string which is a duplicate of the string
  // I have to use "strdup" to prevent warning of a string literal being assigned to a non constant char*
  char *user = strdup("octocat");
  app.add_option("-u,--user", user, "The GitHub username");

  try {
    (app).parse((argc), (argv));
  } catch(const CLI::ParseError &e) {
    return (app).exit(e);
  }

  CURL *curl;
  CURLcode res;
  std::string readBuffer;

  curl = curl_easy_init();

  char *URL = strcat(strdup("https://api.github.com/users/"), user);

  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, URL);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "GitHub CLI/0.1");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    std::cout << readBuffer << std::endl;

    return 0;
  } else {
    return -1;
  }
}
