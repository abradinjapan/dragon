debug:
	gcc ./source/main.c -Wall -Wextra -fsanitize=address -g -o ./../dragon.elf

release:
	gcc ./source/main.c -Wall -Wextra -o ./../dragon.elf
