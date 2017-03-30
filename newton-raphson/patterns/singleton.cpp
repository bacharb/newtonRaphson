// Header file Singleton.h
class Singleton {
	public:
		static Singleton* Instance() {
			if (!pInstance_)
				pInstance_ = new Singleton;
			return pInstance_;
		}
	private:
			Singleton(); // Prevent clients from creating a new Singleton
			Singleton(const Singleton&); // Prevent clients from creating // a copy of the Singleton
			static Singleton* pInstance_; // The one and only instance
};

// Implementation file Singleton.cpp
Singleton* Singleton::pInstance_ = 0;

