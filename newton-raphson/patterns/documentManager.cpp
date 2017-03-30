

class DocumentManager{
	public:
		Document* NewDocument();
	private:
		virtual Document* CreateDocument() = 0;
		list<Document*> listOfDocs_;
};

Document* DocumentManager::NewDocument() {
	Document* pDoc = CreateDocument();
	listOfDocs_.push_back(pDoc);
	return pDoc;
}
