OPTIONS = -Wall -Werror -O -o 

%.out: %.c
	gcc $(OPTIONS) $@ $<
	cat $< | xclip -selection c
	./$@
