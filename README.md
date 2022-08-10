# GitHub CLI

A C++ CLI for GitHub. It uses [libcurl](https://curl.se/libcurl/) to perform HTTP requests and [CLI11](https://github.com/CLIUtils/CLI11) to parse the arguments.

## References

* https://curl.se/libcurl/
* https://docs.github.com/en/rest
* https://github.com/CLIUtils/CLI11

## Compile

```
g++ -std=gnu++17 -Ofast main.cpp -lcurl -o github
```






git remote add origin https://github.com/simonespa/GitHubCLI.git

git pull origin main

git push -u origin main
