
int main () {

	SubClass subobject;

	subobject.Metodo(); //Richiama il metodo della SubClass
	
	subobject.SuperClass::Metodo(); //Richiama il metodo della SuperClass

	SuperClass* ptr = &subobject;

	ptr->Metodo();
	
}
