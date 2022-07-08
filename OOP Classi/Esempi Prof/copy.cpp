class name_class {

	public:

	//costruttore principale
	name_class (int attributo) {

		attributo_p = attributo;
	}
	//default constructor
	name_class () {

		attributo_p = 0; //assegno valore predefinito
	}	
	//copy constructor
	name_class (const name_class& original) {

		attributo_p = original.attributo_p;
	}

	private:

	int attributo_p

};
