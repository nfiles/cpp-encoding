#!/bin/sh

printf "\n> Building...\n"
if make build; then
	if [ -a ./bin/encoding.exe ]; then
		printf "\n> Running...\n"
		./bin/encoding.exe 'Hello, World!'\
						   'My name is Nathan.'\
						   'Lorem Ipsum dolor sit amet'
	else
		printf "\n> File not found (./bin/encoding.exe)\n"
	fi
else
	printf "\n> Error building target ($?)\n"
fi
