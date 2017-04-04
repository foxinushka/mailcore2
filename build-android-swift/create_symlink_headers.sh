#!/bin/sh

sources_path="$(pwd)/../src/c"
headers_path="$(pwd)/include/MailCore/${@##*/}"

rm -rf "${headers_path}"
mkdir -p "${headers_path}"

function recursive_observe {
	for f in "$1"/*
	do
		if [ -f "$f" ]; then
			if [[ "$f" == *.h ]]; then
				echo "create symlinks for $f";
				ln -s "$f" "${headers_path}"
			fi
		else 
			if [ -d "$f" ]; then
				echo "recursive entrance $f";
				recursive_observe "$f"
			fi
		fi
	done
}
for var in "$sources_path"
do
	recursive_observe "$var"
done