#!/usr/bin/env bash

cd /tmp

mkdir getproject
url=https://bacharb.visualstudio.com/_git/MyFirstProject
git init

remote add -f -t master -m master origin $url

git merge origin

