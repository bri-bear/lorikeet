lorikeet: main.c
	$(CC) main.c -lxcb -o lorikeet

install:
	@cp -p lorikeet $(DESTDIR)$(PREFIX)/bin/lorikeet
	@chmod +x $(DESTDIR)$(PREFIX)/bin/lorikeet

build-test:
	$(CC) main.c -lxcb -o lorikeet
	@Xephyr :1
	@DISPLAY=:1 ./lorikeet
