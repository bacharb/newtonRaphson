#!/usr/bin/env python

import pylru
import web 


store={}
urls = (
			'/',						'index', 
         '/list',             'listKeys',    # Dump the whole store
         '/set?(.*)',         'setVal',      # set the value of a key
         '/del/(.*)',         'delKey',      # delete a key from store,
         '/expand/(.*)',      'expand'       # expand all place holder keys from the store contained in a string. 
      )   

class index:
	def GET (self) :
		return "Hello"
class setVal:
   def POST (self, key):
      data = web.input()
      for key in data : 
         store[key] = data[key]

class listKeys:    
   def GET (self): pass

class delKey:
   def POST(self, key):
      data = web.input()
      for key in data.keys():
         if key in store: del store[key]

class expand:
   def GET(self, string):
      return string


app = web.application(urls,globals())

if __name__ == "__main__":
    app.run() 
    

