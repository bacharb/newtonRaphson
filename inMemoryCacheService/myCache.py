import pylru

class inMemoryCache(object):
    def __init__(self, size=3, cacheMgr=pylru.WriteThroughCacheManager):
        self._store = {}
        self._cache = cacheMgr(self._store, size)
        self._cacheMgr = cacheMgr

    def __len__(self):
        return len(self._cache)

    def __contains__(self, key):
        return key in self._cache

    def __getitem__(self, key):
        if key in self._cache:
            return self._cache[key]
        return None

    def __setitem__(self, key, value):
        self._cache[key] = value

    def __delitem__(self, key):
        if key in self._cache:
            del self._cache[key]

    def keys(self):
        keys = set(self._cache.keys())
        return keys

    def value(self,key): return self._cache[key]

    def items(self):
        return dict(self._cache.items())

    def clear(self):
        self._cache.clear()
        self._store = {}