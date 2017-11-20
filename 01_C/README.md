### How to compile with gcc
Once we have the source code (.c file) we create an object of this with
```
$ gcc -c source_code.c
```
Here c flag stands for assemble the object file but do not link. If flag _-o "file_object.o"_ is not given we got a _source\_code.o_ by default.
After this, we compile the object file in a executable file with
```
$ gcc source_code.o -o "executable.out"
```
To execute this file we make
```bash
$  ./executable.out
```
And it's done! :octocat:
