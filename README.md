# Jikan
A simple commandline timestamp logger.  Jikan (時間) is Japanese for time.

## TODO
- [ ] Log [tags]
- [ ] Todolist [add, start, done]
- [ ] STATS 
- [ ] EXPORT [html, csv]

## Build
1. Update `path` and `filename` in `jikan.cpp`
2. Run ` ./build.sh `

## Add path
Add current repository path to `.bashrc` like so:
```
# .bashrc 
    PATH="$PATH:<jikan-repository-path>"
```
Run `source ~/.bashrc` to reload bashrc

Jikan can now be run using `$ jikan `

## Print log
Print logs after setting path in bashrc as follows:

``` cat `jikan file` ```

## Format
Accepted format:
``` 
$ jikan <heading> <details>
$ jikan stats
$ jikan path
$ jikan file
```
## References
&lt;ctime&gt; [link](https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm)

