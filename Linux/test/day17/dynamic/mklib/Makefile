libSnowK.so:mymath.o myprint.o
	gcc -shared mymath.o myprint.o -o libSnowK.so
mymath.o:mymath.c
	gcc -fPIC -c mymath.c -o mymath.o

myprint.o:myprint.c
	gcc -fPIC -c myprint.c -o myprint.o

# 打包
.PHONY:SnowK
SnowK:
	mkdir -p SnowK/lib SnowK/include
	cp -rf *.h SnowK/include
	cp -rf *.so SnowK/lib

.PHONY:clean
clean:
	rm -rf *.o libSnowK.so 
