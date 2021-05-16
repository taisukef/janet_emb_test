cp janet-v1.15.5-osx/lib/libjanet.so libjanet.so.1.15
gcc -I janet-v1.15.5-osx/include -L janet-v1.15.5-osx/lib/ -ljanet main.c

