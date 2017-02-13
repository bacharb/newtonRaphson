#!/usr/bin/env python

import pylru
import web
import datetime
import re

class inMemoryCache (object) :
	def __init__ (self, size= 3, cacheMgr = pylru.WriteThroughCacheManager ):  
		self._store = {}
		self._cache = cacheMgr(self._store, size)
		self._cacheMgr = cacheMgr
    
	def __len__(self) :
		return len(self._cache)

	def __contains__(self, key) :
		return key in self._cache

	def __getitem__(self, key) :
		if key in self._cache:
			return self._cache[key]
		return None

	def __setitem__(self, key, value) :
		self._cache[key] = value
            
	def __delitem__(self, key) :
		if key in self._cache :
			del self._cache[key]
         
	def keys(self) :
		keys = set(self._cache.keys())
		return keys

	def items(self) :
		return dict(self._cache.items())

store = inMemoryCache ()

urls = (
			'/list', 				'listKeys',		# Dump the whole store
			'/set?(.*)', 			'setVal',		# set the value of a key
			'/del?(.*)', 			'delKey',		# delete a key from store,
			'/expand?(.*)', 		'expand'			# expand all place holder keys from the store contained in a string. 
		)

app = web.application(urls, globals())

class setVal:
	def POST (self, key):
		data = web.input()
		for key in data : 
			store._cache[key] = data[key]

class listKeys:        
	def GET (self):
		return store.items()

class delKey:
	def POST(self, key):
		data = web.input()
		for key in data.keys():
			if key in store: 
				del store[key]

class expand:
	def POST(self, string):
		fields = dict(store.items())
		fields['today'] = datetime.datetime.now().isoformat()
		
		fields['name'] = 'Bachar'
		fields['weather'] = '2.7'

		inputString = list(dict(web.input()))[0]
		
		for placeholder, key in re.findall('(\$\{([a-z]+)\})', inputString):
			inputString = inputString.replace(placeholder, fields.get(key, placeholder)
)
		return inputString

if __name__ == "__main__":
    app.run()
