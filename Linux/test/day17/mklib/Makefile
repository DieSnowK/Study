libSnowK.a:mymath.o myprint.o
	ar -rc libSnowK.a mymath.o myprint.o

mymath.o:mymath.c
	gcc -c mymath.c -o mymath.o

myprint.o:myprint.c
	gcc -c myprint.c -o myprint.o

# 打包
.PHONY:SnowK
SnowK:
	mkdir -p SnowK/lib SnowK/include
	cp -rf *.h SnowK/include
	cp -rf *.a SnowK/lib

.PHONY:clean
clean:
	rm -rf *.o libSnowK.a
