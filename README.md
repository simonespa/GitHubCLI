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

## Usage

By default it returns the `octocat` user information. You can use `jq` to parse the JSON output.

```
./github | jq
```

Otherwise, it is possible to specify a user.

```
./github -u simonespa | jq
```

To get help about the command, run the following.

```
./github -h
```
