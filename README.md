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

## Usage
``` 
usage: jikan <command> [<args>]
These are common Jikan commands:

log task
   <head> <desc>        Adds a task of type 'work'

print paths
   path                 Show repository path
   file                 Show logfile path
   todo                 Show todo path

todo list
   add <item>           Adds a todo item
   remove <item>        Removes a todo item

stats
   stats                Show statistics
```
## References
&lt;ctime&gt; [link](https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm)

