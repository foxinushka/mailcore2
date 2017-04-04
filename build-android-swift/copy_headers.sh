#!/bin/bash

sources_path="$(pwd)/../src"
headers_path="$(pwd)/include/MailCore/${@##*/}"

rm -rf "${headers_path}"
mkdir -p "${headers_path}"

function recursive_observe {
	for f in "$1"/*
	do
		if [ -f "$f" ]; then
			if [[ "$f" == *.h ]]; then
				echo "create symlinks for $f";
				cp "$f" "${headers_path}"
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

cp $(pwd)/../src/core/basetypes/MCICUTypes.h "${headers_path}"
cp $(pwd)/../src/swift/swiftmailcore2-Bridging-Header.h "${headers_path}"
