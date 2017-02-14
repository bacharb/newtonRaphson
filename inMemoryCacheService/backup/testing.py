#!/usr/bin/env python
import unittest
import requests
import ast

class TestInMemoryCacheService(unittest.TestCase):
	def setUp(self):
		r = requests.get('http://127.0.0.1:8080/reset')
		self.assertTrue(r.ok)
     
	def tearDown(self):
		r = requests.get('http://127.0.0.1:8080/reset')
		self.assertTrue(r.ok)

	def test_set(self):
		data = {'name':'bachar bouazza', 'address':'Chicago'}
		r = requests.post('http://127.0.0.1:8080/set', data)
		self.assertTrue(r.ok)
		r.close()
		d = dict(ast.literal_eval(r.text))

		self.assertTrue(set(d.values()) == set(data.values()) and set(d.keys()) == set(data.keys()))

		r = requests.get('http://127.0.0.1:8080/list')
		
		d = dict(ast.literal_eval(r.text))
		assert (bool(d)) # the result is not empty 
		assert(set(d.values()) == set(data.values()) and set(d.keys()) == set(data.keys()))

	def test_reset(self): 
		r = requests.get('http://127.0.0.1:8080/reset')
		self.assertTrue(r.ok)
		
		r = requests.get('http://127.0.0.1:8080/list')
		self.assertTrue(r.ok)
		d = dict(ast.literal_eval(r.text))
		assert (not bool(d)) # the result is not empty 

		for i in range(1,10): 
			key = 'name' + str(i)
			value = 'Speedy'+str(i)
			data = {key:value}
			r = requests.post('http://127.0.0.1:8080/set', data)
			assert(r.ok)
		
		r = requests.get('http://127.0.0.1:8080/reset')
		self.assertTrue(r.ok)

		r = requests.get('http://127.0.0.1:8080/list')
		self.assertTrue(r.ok)
		d = dict(ast.literal_eval(r.text))
		assert (not bool(d)) # the result is not empty 

	def test_del(self): 
		anyKey="anykey"
		r = requests.post('http://127.0.0.1:8080/del', anyKey)
		self.assertTrue(r.ok)
		d = dict(ast.literal_eval(r.text))
		assert (not bool(d)) # the result is not empty 

		key   = 'name'
		value = 'Bachar Bouazza' 
		data = {key:value}
		r = requests.post('http://127.0.0.1:8080/set', data)
		self.assertTrue(r.ok)

		r = requests.post('http://127.0.0.1:8080/del', key)
		self.assertTrue(r.ok)

		d = set(ast.literal_eval(r.text))
		self.assertTrue(d == {key}) 
		
	def test_list(self): # We assum an empty store.
		keysAndValues = {}
		for i in range(1,10): 
			key = 'name' + str(i)
			value = 'Speedy'+str(i)
			data = {key:value}
			r = requests.post('http://127.0.0.1:8080/set', data)
			assert(r.ok)
			keysAndValues[key] = value

		r = requests.get('http://127.0.0.1:8080/list')
		d = dict(ast.literal_eval(r.text))
		assert (bool(d)) # the result is not empty 
		
		assert(set(d.values()) == set(keysAndValues.values()) and set(d.keys()) == set(keysAndValues.keys()))

	def test_expand(self):
		data = {'name':'Speedy', 'address': 'Chicago'}
		r = requests.post('http://127.0.0.1:8080/set', data)
		self.assertTrue(r.ok)
		r.close()
		textToExpand      = 'Hello, my name is ${name} living in ${address}'
		expectedExpansion = 'Hello, my name is Speedy living in Chicago'
		r = requests.post('http://127.0.0.1:8080/expand', textToExpand)
		self.assertTrue(r.ok)
		assert (r.text == expectedExpansion)

	def test_Overload(self):
		data = {'name':'Speedy', 'address': 'Chicago'}
		for x in range(0, 10):
			data = {'name' + str(x):'Speedy'+str(x), 'address'+str(x): 'Chicago'+str(x)}
			r = requests.post('http://127.0.0.1:8080/set', data)
			r = requests.post('http://127.0.0.1:8080/del', data)
			self.assertTrue(r.ok)
		
		r = requests.get('http://127.0.0.1:8080/list')
		self.assertTrue(r.ok)

		r.close()


if __name__ == '__main__':
	unittest.main()
