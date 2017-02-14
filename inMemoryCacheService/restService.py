#!/usr/bin/env python

import web
import datetime
import re

import myCache

store = myCache.inMemoryCache ()

urls = (
    '/list', 				'listKeys',		# Dump the whole store
    '/reset', 				'reset',		# Reset: resart from scratch ==> cache={} and store ={}.
    '/set?(.*)', 			'setVal',		# set the value of a key
    '/del?(.*)', 			'delKey',		# delete a key from store,
    '/expand?(.*)', 		'expand'		# expand all place holder keys from the store contained in a string.
    )

app = web.application(urls, globals())

class setVal:
    def POST (self, key):
        data = web.input()
        for key in data :
            store._cache[key] = data[key]
        return dict(data)

class listKeys:
    def GET (self):
        return store.items()

class reset:
    def GET (self):
        store.clear()

class delKey:
    def POST(self, key):
        data = web.input()
        deletedKeys = {}
        for key in data.keys():
            if key in store:
                deletedKeys[key] = data[key]
                del store[key]
        return deletedKeys

class expand:
    def POST(self, string):
        fields = dict(store.items())
        fields['today'] = datetime.datetime.now().isoformat()

        inputString = list(dict(web.input()))[0]

        for placeholder, key in re.findall('(\$\{([a-z]+)\})', inputString):
            inputString = inputString.replace(placeholder, fields.get(key, placeholder)
)
        return inputString

if __name__ == "__main__":
    app.run()
