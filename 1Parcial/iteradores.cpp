/*begin( ) devuelve un iterador de tipo iterator.
cbegin( ) devuelve un iterador de tipo const_iterator.
¿ Y que diferencia hay ? Pues muy sencillo también:

Un iterator permite modificar aquello a lo que apunta:

*string.begin( ) = 'A'; // Ok
Un const_iterator no permite modificar aquello a lo que apunta:

*string.cbegin( ) = 'A'; // Error !!
Ten en cuenta que begin( ) devuelve una cosa u otra dependiendo del const del objeto:

const std::string test;
auto iter = test.begin( ); // <-- const_iterator

std::string test;
auto iter = test.begin( ); // <-- iterator
Mientras que cbegin( ) siempre devuelve un const_iterator:

const std::string test;
auto iter = test.cbegin( ); // <-- const_iterator

std::string test;
auto iter = test.cbegin( ); // <-- const_iterator
Normalmente, pera evitar funcionalidades no deseadas, se usa cbegin( ) para garantizar que no modificamos sin querer el contenido de la cadena: el compilador genera un error si intentamos modificar el contenido.
*/

//Por tanto hay que utilizar tanto el const para el begin por si acaso y el cbegin para asegurarse