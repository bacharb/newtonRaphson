import datetime
import re

import myCache
import web

webStore = myCache.inMemoryCache()

urls = (
    '/list', 'listKeys',  # Dump the whole store
    '/reset', 'reset',  # Reset: resart from scratch ==> cache={} and store ={}.
    '/set?(.*)', 'setVal',  # set the value of a key
    '/del?(.*)', 'delKey',  # delete a key from store,
    '/expand?(.*)', 'expand'  # expand all place holder keys from the store contained in a string.
)

class setVal:
    def POST(self, key):
        data = web.input()
        for key in data:
            webStore[key] = data[key]
        return dict(data)


class listKeys:
    def GET(self):
        return webStore.items()


class reset:
    def GET(self):
        webStore.clear()


class delKey:
    def POST(self, key):
        data = web.input()
        deletedKeys = {}
        for key in data.keys():
            if key in webStore:
                deletedKeys[key] = data[key]
                del webStore[key]
        return deletedKeys


class expand:
    def POST(self, string):
        fields = dict(webStore.items())
        fields['today'] = datetime.datetime.now().isoformat()

        inputString = list(dict(web.input()))[0]

        for placeholder, key in re.findall('(\$\{([a-z]+)\})', inputString):
            inputString = inputString.replace(placeholder, fields.get(key, placeholder)
                                              )
        return inputString

serviceInterfaces = {
    "expand": expand,
    "setVal": setVal,
    "listKeys": listKeys,
    "delKey": delKey,
    "reset": reset
}

app = web.application(urls, serviceInterfaces)
