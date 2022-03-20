/**
 * Estudientes:
 *
 */

#include <iostream>
#include <math.h>
#include <boost/multiprecision/cpp_bin_float.hpp>
//Se considera para cada una de los problemas las siguientes constantes 
const float tol = 0.00000001; //Tolerancia máxima soportada para cada método
const int iterMax = 5000;     //Cantidad máxima de iteraciones para cada un de los métodos
using namespace std;
using namespace boost::multiprecision;
/**
 * Esta parte de la tarea consiste en implementar computacionalmente en C++ algunas de
 * las preguntas desarrolladas en la Partes 1 y 2.
 * Para este caso se elige utilizar parte 1 e implementarla en el lenguaje C++
 * Parte #1
 *  Esta parte de la tarea consiste en desarrollar un paquete computacional en C++ que permita aproximar el valor
 *  numérico de un conjunto de funciones trascendentes de variable real utilizando únicamente las operaciones de suma (+),
 *  resta (-), multiplicación (*) y potencia de exponente entero positivo (^). No pueden usar la división (/)
 */
class Parte1 {
public: Parte1(){ }
public:
    /** Esta función retorna el inverso de un número ingresado
     * @param x Numero para obtener inverso
     * @return Retorna el valor en inverso de la entrada
     */
    cpp_bin_float_50 div_t(cpp_bin_float_50 x){
        cpp_bin_float_50 resultado_inverso; //Variable para el resultado final
        cpp_bin_float_50 x_0; //Variable para ingresar el valor inicial
        cpp_bin_float_50 eps = 2.220446049250313 * 0.0000000000000001; //Variable para la precisión relativa de punto flotante
        //Determinación del rango del valor ingresado
        //Se realiza un caso de inicio donde el dato ingresado es 1
        if (x == 1) {
            //En este caso no se aplica la variable eps ni el función factorial
            //Se retornal un 1 directamente si  se diera dicho caso
            resultado_inverso = 1;
            return resultado_inverso;
        }
        //Caso 1: eps^15 si 80! < a <= 100!
        if (factorial(80) < x && x <= factorial(100)) {
            x_0 = pow(eps,15); // Se aplica el valor inicial correspondiente
        //Caso 2: eps^11 si 60! < a <= 80!
        } else if (factorial(60) < x && x <= factorial(80)) {
            x_0 = pow(eps,11); // Se aplica el valor inicial correspondiente
        //Caso 3: eps^8 si 40! < a <= 60!
        } else if (factorial(40) < x && x <= factorial(60)) {
            x_0 = pow(eps,8); // Se aplica el valor inicial correspondiente
        //Caso 4: eps^4 si 20! < a <= 40!
        } else if (factorial(20) < x && x <= factorial(40)) {
            x_0 = pow(eps,4); // Se aplica el valor inicial correspondiente
        //Caso 5: eps^2 si 0 < a <= 20!
        } else if ( 0 < x && x <= factorial(20)) {
            x_0 = pow(eps,2); // Se aplica el valor inicial correspondiente
        }
        //Se tiene como aproximación la siguiente expresión 
        // x_k+1 = x_k*(2-a*x_k)
        //Se comienza el proceso iterativo para hallar el valor 
        cpp_bin_float_50 x_k = x_0; //VAriable con el valor inicial de la sección anterior
        cpp_bin_float_50 x_k_1; //Variable para la iteración siguiente a la inicial
        cpp_bin_float_50 error; //Variable con el error obtenido por el método
        for(int k = 0; k < iterMax; k++) {
            x_k_1 = x_k*(2 - (x*x_k)); //Se aplica la expresión iterativa
            error = abs((x_k_1 - x_k) * pow(x_k_1,-1)); //Se va determinando el error
            //Si el error susperará la tolerancia
            if (error < tol) {
                resultado_inverso = x_k_1; //Se retorna el valor inverso
                break;
            }
            x_k = x_k_1;
            k++;
        }
        return resultado_inverso; 
    }

    /** Esta función retorna el valor de seno del valor ingresado
     * @param x Un número el cual se le calculará el seno
     * @return El calor de seno calculado
     */
    cpp_bin_float_50 sin_t(cpp_bin_float_50 x){
        cpp_bin_float_50 s_k = 0;  //Variable para la expresión de la iteración 
        cpp_bin_float_50 s_k_1 = 0; //Variable para la expresión de la iteración consecutiva
        cpp_bin_float_50 signo; //Variable para controlar el signo que lleva la expresión del método
        cpp_bin_float_50 exponente; //Variable para llevar el control del exponente de la expresión del método
        //Para manejar mejor el formato de la expresión se divide en numerador y denominador
        cpp_bin_float_50 numerador; //Variable para llevar el numerador de la expresión
        cpp_bin_float_50 denominador; //Variable para llevar el deominador de la expresión
        cpp_bin_float_50 error; //Variable para tomar el control del error del método
        cpp_bin_float_50 resultado_seno; //Variable para mostrar el valor del seno del método
        //Se accede al ciclo para iterar sobre la expresión del método
        for (int k = 0; k < iterMax; k++) {
            signo = pow(-1,k); //Corresponde a la parte del -1 elevado al contador de la iteración
            exponente = 2*k + 1; //Corresponde a la parte del exponente de la expresión de la iteración
            //Control de las partes de las expresiones
            numerador = pow(x, exponente); //Se eleva al exponente entero de la expresión
            denominador = factorial(exponente); //Se obtiene el factorial del denominador
            //Note que según la expresión del denominador es la misma que el exponente
            //por eso se reutiliza la variable 
            denominador = div_t(denominador); //Se obtiene el inverso del denominador, al no poder usarse pow
            s_k = s_k + (signo * numerador * denominador); //Se aplica la iteración sobre la componente sk
            signo = pow(-1,k + 1); //Corresponde a la parte del -1 elevado al contador de la iteración
            exponente = 2*(k + 1) + 1; //Corresponde a la parte del exponente de la expresión de la iteración
            //Control de las partes de las expresiones
            numerador = pow(x, exponente); //Se obtiene el factorial del denominador
            denominador = factorial(exponente); //Se obtiene el factorial del denominador
            //Note que según la expresión del denominador es la misma que el exponente
            //por eso se reutiliza la variable 
            denominador = div_t(denominador); //Se obtiene el inverso del denominador, al no poder usarse pow
            s_k_1 = s_k + (signo * numerador * denominador);  //Se aplica la iteración sobre la componente sk+1
            error = abs(s_k_1 - s_k); //Se obtiene el error obtenido por el método 
            //Si el error del método supera la tolerancia propuesta
            if (error < tol) {
                resultado_seno = s_k_1;  //Se devuelve el resultado como el resultado de la iteración actual
                break;
            }
        }
        return resultado_seno;
    }

    /** Función que calcula el valor de tangente de un valor iniciar ingresado
     * @param x Valor al cual se le calculará la tangente
     * @return El valor de la tangente del valor ingresado
     */
    cpp_bin_float_50 tan_t(cpp_bin_float_50 x){
        cpp_bin_float_50 numerador; //Corresponde a la sección del numerador de la expresión para la tangente
        cpp_bin_float_50 denominador; //Corresponde a la sección del denominador de la expresión para la tangente
        cpp_bin_float_50 resultado_tengente; //Variable para expresar el resultado del método para la tangente
        numerador = sin_t(x); //Se llama la función de del método para el numerador
        denominador = cos_t(x);    //Se llama la función del método para el denominador
        //Se analiza el caso del coseno
        //Si el coseno es cero muestra un error por error en operación
        if (denominador == 0) {
            cout << "NO es posbile efectuar la operación, ya que el coseno tiene como valor 0" << endl;
            return 0;
        }
        //Si el coseno por el contrario es mayor que cero
        if (denominador > 0) {
            denominador = div_t(denominador); //Se obtiene el inverso del denominador, ya que no se puede usar la división
            resultado_tengente = numerador * denominador; //Se procede a aplicar las funciones 
        } else {
            //Si el denominador diera menor que cero se trabaja con el abs, pero de multiplica por 1
            denominador = -1 * div_t(abs(denominador));
            resultado_tengente = numerador * denominador;
        }
        return resultado_tengente; //Se devuelve el valor de la tangente para el método
    }

    /** Esta función calcula la paroximación el logaritmo del número x con base a
     * @param x Es el valor del número al que se le aplicará el logaritmo
     * @param a es el valor de la base del logaritmo
     * @return resultado de la aproximación log a (x)
     */
    cpp_bin_float_50 log_t(cpp_bin_float_50 x, cpp_bin_float_50 a){
        cpp_bin_float_50 resultado_log;  //Variable para mostrar el resultado del logaritmo del método
        //Se revisa el denominador que cumpla el requisito que sea mayor que cero
        if (x <= 0) {
            cout << "No se puede proceder con la operación el argumento es inválido" << endl;
            return 0;
        }
        //Se retorna el valor del logaritmo en base a
        //Para ello se hace uso de la propiedad de ln (x) / ln (a)
        resultado_log = ln_t(x) * div_t(ln_t(a));   
        return resultado_log; //Se devuelve el resultado del logaritmo 
    }

    /** Esta funcion retorna el resultado aproximado del seno hiperbolico 
     * @param x el valor al que se le aplica seno hiperbolico
     * @return resutlado aproximado de la funcion
     */
    cpp_bin_float_50 sinh_t(cpp_bin_float_50 x){
        cpp_bin_float_50 x_k;  //Variable para la iteración del método
        cpp_bin_float_50 x_k_1; //Variable para la iteraición siguiente del método
        cpp_bin_float_50 numerador; //Corresponde a el denominador del metodo
        cpp_bin_float_50 denominador; //Corresponde a el numerador del metodo
        cpp_bin_float_50 error; //Corresponde al error presentado por el método
        cpp_bin_float_50 resultado; //Corresponde al error dado por el método
        //Calculamos el primer valor de la iteracion
        x_k = x; // el valor inicial siempre es 1
        //se inicia con la iteración del método
        for (int k = 1; k < iterMax; k++) {
            //Calculamos la siguiente iteracion
            numerador = pow(x , ((2 * k) + 1 )); // calculo del numerador
            denominador = factorial(((2 * k) + 1 )); //Calculo del denominador
            x_k_1 = x_k + (numerador * div_t(denominador)); // calculo del primero valor
            error = abs(x_k_1 - x_k);//Se cálculo el error asociado al método
            resultado = x_k_1; // el resultado cambia
            //Si el error se pasa de la tolerancia
            if (error < tol) {
                //Se devuelve el resultado con la última iteración
                break;
            }
            x_k = x_k_1; // para que se pueda seguir con la iteracion el nuevo resultado para a ser x_k   
        }
        return resultado;
    }

    /** Funcion que aproxima la tangente hiperbolica de un numero dado
     * @param x numero al que se le calcula la tangente hiperbolica
     * @return resutlado aproximado de la tangente hiperbolica
     */
    cpp_bin_float_50 tanh_t(cpp_bin_float_50 x){
        cpp_bin_float_50 numerador; //Corresponde a el denominador del metodo
        cpp_bin_float_50 denominador; //Corresponde a el numerador del metodo
        cpp_bin_float_50 resultado; //Corresponde al error dado por el método
        // Hacemos los calculos necesarios
        // Como la tanh = senh/consh
        numerador = sinh_t(x); // calculamos el numerador
        denominador = cosh_t(x); // Calculamos el denominador 
        resultado = numerador * div_t(denominador); // calculamos la division
        return resultado; // retornamos el resutlado aprximado de la tangente hiperbolica
    }

    /** Esta funcion calcula la raiz de un numero dada el indice
     * @param x es el numero al que se le aplica la raiz
     * @param a es el indice de la raiz
     * @return aproximacion de la raiz 
     */
    cpp_bin_float_50 root_t(cpp_bin_float_50 x, cpp_bin_float_50 a){
       cpp_bin_float_50 resultado_raiz_c;  //Variable para devolver el valor de la raiz cuadrada

        //Se revisa que el dato ingresado no sea igual que cero, de lo contrario procede
        if (x < 0) {
            cout << "Error - La base ingresada es invalida" << endl;
            resultado_raiz_c = 0;       //Se devuelve el valor como cero  
        } else {
            resultado_raiz_c = Newton_Raphson(x,a);    //Se aplica el método de Newton Raphson
        }
        return resultado_raiz_c; //Se devuelve el valor de la raíz cuadrada 
    }

    /** Esta funcion calcula el valor aproximado de tangente a la menos 1 de un valor ingresado
     * @param x valor al cual se le calculara el tangente inverso
     * @return resultado aproximado de la operacion
     */
    cpp_bin_float_50 atan_t(cpp_bin_float_50 x){
        cpp_bin_float_50 x_k;  //Variable para la iteración del método
        cpp_bin_float_50 x_k_1; //Variable para la iteraición siguiente del método
        cpp_bin_float_50 numerador; //Corresponde a el denominador del metodo
        cpp_bin_float_50 denominador; //Corresponde a el numerador del metodo
        cpp_bin_float_50 signo; //Corresponde al signo de la operacion
        cpp_bin_float_50 error; //Corresponde al error presentado por el método
        cpp_bin_float_50 resultado; //Corresponde al error dado por el método
        cpp_bin_float_50 division; //Corresponde a la division de los valores
        //Validacion de solo se pueden valores [-1,1]
        if(x > 1 || x < -1){
            cout << "Error - El numero ingresado esta fuera del dominio" << endl;
        }
        //Calculamos el primer valor de la iteracion
        x_k = x; // el valor inicial siempre es 1
        //se inicia con la iteración del método
        for (int k = 1; k < iterMax; k++) {
            //Calculamos la siguiente iteracion
            numerador = pow(x , ((2 * k) + 1 )); // calculo del numerador
            denominador = ((2 * k) + 1 ); //Calculo del denominador
            signo = pow( -1 , k ); // calculo del signo
            division = numerador * div_t(denominador); // resultado de la division
            x_k_1 = x_k + (signo * division); // calculo del primero valor
            error = abs(x_k_1 - x_k);//Se cálculo el error asociado al método
            resultado = x_k_1; // el resultado cambia
            //Si el error se pasa de la tolerancia
            if (error < tol) {
                //Se devuelve el resultado con la última iteración
                break;
            }
            x_k = x_k_1; // para que se pueda seguir con la iteracion el nuevo resultado para a ser x_k   
        }
        return resultado;

    }

    /** Esta función retorn el valor de e elevado a un valor ingresado x
     * @param x Este es el valor del número que se elevará e
     * @return el resultado aproximado del número de base e con exponente x
     */
    cpp_bin_float_50 exp_t(cpp_bin_float_50 x){
        cpp_bin_float_50 s_k = 0; //Variable para la expresión de la iteración 
        cpp_bin_float_50 s_k_1 = 0; //Variable para la expresión de la iteración consecutiva
        cpp_bin_float_50 error; //Variable para el control del error del método
        cpp_bin_float_50 resultado_exponencial; //Variable para encontrar el resultado del exponente con el método
        //Para manejar mejor el formato de la expresión se divide en numerador y denominador
        cpp_bin_float_50 numerador; //Numerador de la expresión 
        cpp_bin_float_50 denominador; //Denominador de la expresión
    
        //Se accede al ciclo para calular la aproximación del exponente
        for (int k = 0; k < iterMax; k++) {       
            //Note que k representa el de la expresión brindada por la tarea
            //Iteración para el sk de la expresión
            numerador = pow(x, k);  //Se eleva el exponente a la iteración del contador     
            denominador = factorial(k); //En el denominador se aplica el factorial
            denominador = div_t(denominador); //IMPORTANTE: Se saca inversa, ya que no se puede dividir
            s_k = s_k + (numerador * denominador); //Se procede a sacar calcular la expresión dada para el método
            //Iteración para el sk+1 de la expresión
            numerador = pow(x, k + 1); //Se eleva el exponente a la iteración del contador 
            denominador = factorial(k + 1); //En el denominador se aplica el factorial
            denominador = div_t(denominador); //IMPORTANTE: Se saca inversa, ya que no se puede dividir
            s_k_1 = s_k + (numerador * denominador); //Se procede a sacar calcular la expresión dada para el método
            error = abs(s_k_1 - s_k); //Se calcula el error con el sk y sk+1
            //Si el error supera la tolerancia del método se detiene la iteración
            if (error < tol) {
                resultado_exponencial = s_k_1; //Se devuelve el resultado como la última iteración
                break;
            }
        }
        return resultado_exponencial;  //Se devuelve el resultado del cálculo exponencial
    }

    /** Esta función calculará el coseno de un valor ingresado
     * @param x Calor al cual se le aproximará el valor de coseno
     * @return El resiltado según el valor ingresado
     */
    cpp_bin_float_50 cos_t(cpp_bin_float_50 x){
        cpp_bin_float_50 s_k = 0;  //Variable para la expresión de la iteración 
        cpp_bin_float_50 s_k_1 = 0; //Variable para la expresión de la iteración consecutiva
        cpp_bin_float_50 signo; //Variable para controlar el signo que lleva la expresión del método
        cpp_bin_float_50 exponente; //Variable para llevar el control del exponente de la expresión del método
        //Para manejar mejor el formato de la expresión se divide en numerador y denominador
        cpp_bin_float_50 numerador; //Variable para llevar el numerador de la expresión
        cpp_bin_float_50 denominador; //Variable para llevar el deominador de la expresión
        cpp_bin_float_50 error; //Variable para tomar el control del error del método
        cpp_bin_float_50 resultado_coseno; //Variable para mostrar el valor del seno del método
        //Se accede al ciclo para iterar sobre la expresión del método
        s_k = 1;
        for (int k = 1; k < iterMax; k++) {
            exponente = 2 * k; //Corresponde a la parte del exponente de la expresión de la iteración
            numerador = pow(x,exponente); //Se obtiene el exponente de la iteración 
            denominador = factorial(exponente); //Se obtiene el facotrial del exponente en el denominador, ya que es el mismo
            denominador = div_t(denominador); //Se obtiene el inverso del exponente, ya que no se puede usar la división
            s_k_1 = s_k + (pow(-1,k) * numerador * denominador); //Se obtiene el valor sk+1 de la iteración para el método
            error = abs(s_k_1 - s_k); //Se obtiene el valor del error para el método
            //Si el error del método supera a la tolerancia permitida
            s_k = s_k_1;
            if (error < tol) {
                resultado_coseno = s_k_1; //Se devuelve el error como la última iteración
                break;
            }
        
        }
    return resultado_coseno; //Se devuelve el valor del coseno obtenido por el método
    }

    /** Esta función retorna el algoritmo natural de un valor ingresado
     * @param x Es el valor al cual se le aplicará el logaritmo natural
     * @return resultado del algoritmo natural aporximado
     */
    cpp_bin_float_50 ln_t(cpp_bin_float_50 x){
        cpp_bin_float_50 x_k;  //Variable para la iteración del método
        cpp_bin_float_50 x_k_1; //Variable para la iteraición siguiente del método
        cpp_bin_float_50 numeradorDerecha; //Corresponde a el denominador del metodo iterativo
        cpp_bin_float_50 denominadorDerecha; //Corresponde a el numerador del metodo iterativo
        cpp_bin_float_50 multiplicadorDerecha; //Corresponde al numero fuera de la division
        cpp_bin_float_50 divisionDerecha; //Corresponde a la division del metodo iterativo
        cpp_bin_float_50 resultadoDerecha; //Corresponde a la multiplicacion de los elementos en la derecha
        cpp_bin_float_50 resultadoSumatoria; //Corresponde al resultado de la sumatoria anterior
        cpp_bin_float_50 numeradorIzquierda; //Corresponde a el denominador del metodo estatico
        cpp_bin_float_50 denominadorIzquierda; //Corresponde a el numerador del metodo estatico
        cpp_bin_float_50 divisionIzquierda; //Corresponde a la division del metodo esatico
        cpp_bin_float_50 error; //Corresponde al error presentado por el método
        cpp_bin_float_50 resultado; //Corresponde al error dado por el método
        if (x <= 0) {
            cout << "No se puede proceder con la operación el argumento es inválido" << endl;
            return 0;
        }
        //Calculamos el valor de la parte estatica (No iterativa)
        numeradorIzquierda = 2 * (x - 1);//Caluculamos numerador izquierda
        denominadorIzquierda = x + 1; // Calculamos denominador izquierda
        divisionIzquierda = numeradorIzquierda * div_t(denominadorIzquierda); //Calculamos division Izquierda

        //El valor inicial de la iteracion x_k_0 es igual a el resultado de division Izquierda
        x_k = divisionIzquierda;
        resultadoSumatoria = 1; // se calcula el primer valor de la sumatoria
        for (int k = 1; k < iterMax; k++) {
            //Calculamos la siguiente iteracion
            multiplicadorDerecha = 1 * div_t( ((2 * k) + 1 ) );//Calculamos la multiplicacion de la parte iterativa
            numeradorDerecha = x - 1; //calculo numerador derecha
            denominadorDerecha = x + 1; // Calculo denominadro derecha
            divisionDerecha = numeradorDerecha * div_t(denominadorDerecha); // Calculo division derecha
            divisionDerecha = pow(divisionDerecha, (2 * k ) ); //elevamos la division derecha por 2 * k 
            resultadoDerecha = multiplicadorDerecha * divisionDerecha; // resultado de la derecha
            x_k_1 = divisionIzquierda * ( resultadoSumatoria + resultadoDerecha ); //Calculamos el valor iterativo
            error = abs(x_k_1 - x_k);//Se cálculo el error asociado al método
            resultado = x_k_1; // el resultado cambia
            //Si el error se pasa de la tolerancia
            if (error < tol) {
                //Se devuelve el resultado con la última iteración
                break;
            }
            x_k = x_k_1; // para que se pueda seguir con la iteracion el nuevo resultado para a ser x_k
            resultadoSumatoria = resultadoSumatoria + resultadoDerecha; //Se coloca el siguiente calor de la sumatoria
        }
        return resultado;
        
    }

    /** Esta función eleva el valor de a el cual se ingresa como parámetro al valor de x
     * @param x es la cantidad de veces que se va a elevar el valor a
     * @param a es el valor de la base al cual se va a elevear x cantidad de veces
     * @return El resultado de la exponencial
     */
    cpp_bin_float_50 power_t(cpp_bin_float_50 x, cpp_bin_float_50 a){
        cpp_bin_float_50 exponente; //Varibale para la expresion del exponente
        cpp_bin_float_50 resultado_pot; //Variable para llevar el resultado de la potencia
        exponente = ln_t(a) * x; //Se acomoda la expresión del exponente
        resultado_pot = exp_t(exponente); //Se devuelve el reusltado de la potencia
        return resultado_pot; //Se muestra el valor
    }

    /** Esta funcion calcula el valor arpoximado de un coseno hiperbolico
     * @param x es el valor al cual se le calcula el coseno hiperbolico
     * @return resultado aproximaod
     */
    cpp_bin_float_50 cosh_t(cpp_bin_float_50 x){
        cpp_bin_float_50 x_k;  //Variable para la iteración del método
        cpp_bin_float_50 x_k_1; //Variable para la iteraición siguiente del método
        cpp_bin_float_50 numerador; //Corresponde a el denominador del metodo
        cpp_bin_float_50 denominador; //Corresponde a el numerador del metodo
        cpp_bin_float_50 error; //Corresponde al error presentado por el método
        cpp_bin_float_50 resultado; //Corresponde al error dado por el método
        //Calculamos el primer valor de la iteracion
        x_k = 1; // el valor inicial siempre es 1
        //se inicia con la iteración del método
        for (int k = 1; k < iterMax; k++) {
            //Calculamos la siguiente iteracion
            numerador = pow(x , (2 * k)); // calculo del numerador
            denominador = factorial((2 * k )); //Calculo del denominador
            x_k_1 = x_k + (numerador * div_t(denominador)); // calculo del primero valor
            error = abs(x_k_1 - x_k);//Se cálculo el error asociado al método
            resultado = x_k_1; // el resultado cambia
            //Si el error se pasa de la tolerancia
            if (error < tol) {
                //Se devuelve el resultado con la última iteración
                break;
            }
            x_k = x_k_1; // para que se pueda seguir con la iteracion el nuevo resultado para a ser x_k   
        }
        return resultado;
    }

    /** Esta función calcula la paroximación dw raíz cuadrada de x el cual es el valor de entrada
     * @param x es el valor al cual se le aplicará la raíz cuadrada
     * @return resultado de la raiz cuadrada de x
     */
    cpp_bin_float_50 sqrt_t(cpp_bin_float_50 x){
        cpp_bin_float_50 x_k;  //Variable para la iteración del método
        cpp_bin_float_50 x_k_1; //Variable para la iteraición siguiente del método
        cpp_bin_float_50 error; //Corresponde al error presentado por el método
        cpp_bin_float_50 resultado; //Corresponde al error dado por el método
        x_k = x * 0.5; //Valor inicial para comenzar con la iteración de método
        //se inicia con la iteración del método
        for (int k = 0; k < iterMax; k++) {
            //Se procede con la iteración siguiente la método
            x_k_1 = x_k - ( (pow(x_k,2)-x) * div_t(( x_k, 2)  ) );
            error = abs((x_k_1 - x_k) * div_t(x_k_1)); //Se cálculo el error asociado al métod
            resultado = x_k_1; // el resultado cambia
            //Si el error se pasa de la tolerancia
            if (error < tol) {
                return resultado;  //Se devuelve el resultado con la última iteración
            }
            x_k = x_k_1;  //Se asigna la siguiente iteración
        }
        return resultado; //Se devuelve el valor de la iteración
    }
    

    /** Funcion que aproxima el del seno inverso de un valor ingresado
     * @param x Valor al cual se le aplica el seno inverso
     * @return resultado aproximado del seno inverso
     */
    cpp_bin_float_50 asin_t(cpp_bin_float_50 x){
        cpp_bin_float_50 x_k;  //Variable para la iteración del método
        cpp_bin_float_50 x_k_1; //Variable para la iteraición siguiente del método
        cpp_bin_float_50 numerador; //Corresponde a el denominador del metodo
        cpp_bin_float_50 denominador; //Corresponde a el numerador del metodo
        cpp_bin_float_50 multiplicador; //Corresponde al numero fuera de la division
        cpp_bin_float_50 division; //Corresponde a la division del metodo
        cpp_bin_float_50 error; //Corresponde al error presentado por el método
        cpp_bin_float_50 resultado; //Corresponde al error dado por el método
        //Calculamos el primer valor de la iteracion
        x_k = x; // el valor inicial siempre es 1
        //se inicia con la iteración del método
        for (int k = 1; k < iterMax; k++) {
            //Calculamos la siguiente iteracion
            numerador = factorial(2 * k); // calculo del numerador
            denominador = (pow(4,k)) * (pow(factorial(k),2)) * (2*k + 1); //Calculo del denominador
            multiplicador = pow(x,(2 * k + 1)); // calculamos el valor que esta fuera de la division
            division = numerador * div_t(denominador); // calculamos division
            x_k_1 = x_k + division * multiplicador; // calculo del primero valor
            error = abs(x_k_1 - x_k);//Se cálculo el error asociado al método
            resultado = x_k_1; // el resultado cambia
            //Si el error se pasa de la tolerancia
            if (error < tol) {
                //Se devuelve el resultado con la última iteración
                break;
            }
            x_k = x_k_1; // para que se pueda seguir con la iteracion el nuevo resultado para a ser x_k   
        }
        return resultado;
    }

    // ----- Funciones extra necesarias -------//

    /** Funcion Factorial, Esta funcion retorna el numero de entrada en factorial
     * @param n  es el numero natural positivo al que se le aplica factorial
     * @return resultado de la operacion
     */
    cpp_bin_float_50 factorial(cpp_bin_float_50 n){
        if ((n==0)||(n==1)){  //si el numero ingresado es cero o uno
            return 1;         //retorna 1 
        }else{  
            return n*factorial(n-1); // retorna el factorial del numero menos 1
        }
    }

    /** Esta funcion calcula el cero de una funcion
     * @param x numero de entrada para calculo de valores iniciales
     * @param a potencia de la funcion a utilizar
     * @return resultado de la aproximacion
    */
    cpp_bin_float_50 Newton_Raphson(cpp_bin_float_50 x, cpp_bin_float_50 a) {
        cpp_bin_float_50 x_k;  //Variable para la iteración del método
        cpp_bin_float_50 x_k_1; //Variable para la iteraición siguiente del método
        cpp_bin_float_50 error; //Corresponde al error presentado por el método
        cpp_bin_float_50 resultado; //Corresponde al error dado por el método
        cpp_bin_float_50 numerador; //Corresponde al numerador en el metodo
        cpp_bin_float_50 denominador; //Corresponde al denominador en el metodo
        cpp_bin_float_50 division; //Corresponde a la division en el metodo
        x_k = x * 0.5; //Valor inicial para comenzar con la iteración de método

        //se inicia con la iteración del método
        for (int k = 0; k < iterMax; k++) {
            //Se procede con la iteración
            numerador = (pow(x_k, a ) - x ); // se calcula el numerador
            denominador = a * pow( x_k , ( a - 1 ) ); //se calcula el denominador
            division = numerador * div_t(denominador);//se calcula la diviion 
            x_k_1 = x_k - division; // se calcual el metodo
            error = abs((x_k_1 - x_k) * div_t(x_k_1)); //Se cálculo el error asociado al métod
            resultado = x_k_1; // el resultado cambia
            //Si el error se pasa de la tolerancia
            if (error < tol) {
                return resultado;  //Se devuelve el resultado con la última iteración
            }
            x_k = x_k_1;  //Se asigna la siguiente iteración
        }
        return resultado; //Se devuelve el valor de la iteración
}

};



int main(){
    bool testAllFuntionons = true;
    bool test_funtras = false;
    cpp_bin_float_50 n = 15;
    cpp_bin_float_50 a = 4;
    cpp_bin_float_50 i = 0.; // numero entre [-1,1] 
    Parte1 *p1 = new Parte1();
    if(testAllFuntionons){
        cout << "div_t(15) = "     << p1->div_t(n)     << " -> Deberia ser = 0.066667" << endl;
        cout << "sin_t(15) = "     << p1->sin_t(n)     << " -> Deberia ser = 0.650287" << endl;
        cout << "tan_t(15) = "     << p1->tan_t(n)     << " -> Deberia ser = -0.85599" << endl;
        cout << "log_t(15,4) = "   << p1->log_t(n,a)   << " -> Deberia ser = 1.953345" << endl;
        cout << "sinh_t(4) = "     << p1->sinh_t(a)    << " -> Deberia ser = 27.28991" << endl;
        cout << "tanh_t(4) = "     << p1->tanh_t(a)    << " -> Deberia ser = 0.99999"  << endl;
        cout << "root_t(15,4) = "  << p1->root_t(n,a)  << " -> Deberia ser = 1.967989" << endl;
        cout << "atan_t(0.23) = "  << p1->atan_t(0.23) << " -> Deberia ser = 0.226068" << endl;
        cout << "exp_t(4) = "      << p1->exp_t(a)     << " -> Deberia ser = 54.59815" << endl;
        cout << "cos_t(15) = "     << p1->cos_t(n)     << " -> Deberia ser = -0.75968" << endl;
        cout << "ln_t(4) = "       << p1->ln_t(a)      << " -> Deberia ser = 1.38629" << endl;
        cout << "power_t(4,4) = "  << p1->power_t(a,a) << " -> Deberia ser = 256" << endl;
        cout << "cosh_t(4) = "     << p1->cosh_t(a)    << " -> Deberia ser = 27.3082" << endl;
        cout << "sqrt_t(15) = "    << p1->sqrt_t(n)    << " -> Deberia ser = 3.87298" << endl;
        cout << "asin_t(0.23) = "  << p1->asin_t(0.23) << " -> Deberia ser = 0.23207" << endl;
    }
    if(test_funtras){
        cpp_bin_float_50 numerador; //Corresponde a el denominador de la operacion
        cpp_bin_float_50 denominador; //Corresponde a el numerador de la operacion
        cpp_bin_float_50 suma; // Corresponde a la parte de la suma de la operacion 
        cpp_bin_float_50 division; // Es el resultado de la parte de la division
        cpp_bin_float_50 resultado; // resultado Final de la operacion
        cout << " -> Resolviendo: " << endl;    
        cout << "  " << endl;  
        
        numerador = p1->root_t( 3 , ( p1->sin_t( ( 3 * p1->div_t(7) ) ) + p1->ln_t(2) ) );
        denominador = p1->sinh_t( p1->sqrt_t(2) );
        suma = p1->atan_t( p1->exp_t(-1) );
        division = numerador * p1->div_t(denominador);
        resultado = division + suma;

        cout << "El resultado final es = "  << resultado << endl;
    }

}

