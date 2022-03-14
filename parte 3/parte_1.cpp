/**
 * Estudientes:
 *
 */

#include <iostream>
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
        resultado_tengente = cos_t(x);    //Se llama la función del método para el denominador
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

    /**
     * @param x
     * @return
     */
    int sinh_t(string x){
        int result = 0;
        return result;
    }

    /**
     * @param x
     * @return
     */
    int tanh_t(string x){
        int result = 0;
        return result;
    }

    /**
     * @param x
     * @param a
     * @return
     */
    int root_t(string x, string a){
        int result = 0;
        return result;
    }

    /**
     * @param x
     * @return
     */
    int atan_t(string x){
        int result = 0;
        return result;
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
        pp_bin_float_50 s_k = 0;  //Variable para la expresión de la iteración 
        cpp_bin_float_50 s_k_1 = 0; //Variable para la expresión de la iteración consecutiva
        cpp_bin_float_50 signo; //Variable para controlar el signo que lleva la expresión del método
        cpp_bin_float_50 exponente; //Variable para llevar el control del exponente de la expresión del método
        //Para manejar mejor el formato de la expresión se divide en numerador y denominador
        cpp_bin_float_50 numerador; //Variable para llevar el numerador de la expresión
        cpp_bin_float_50 denominador; //Variable para llevar el deominador de la expresión
        cpp_bin_float_50 error; //Variable para tomar el control del error del método
        cpp_bin_float_50 resultado_coseno; //Variable para mostrar el valor del seno del método
        //Se accede al ciclo para iterar sobre la expresión del método
        for (int k = 0; k < iterMax; k++) {
            exponente = 2 * k; //Corresponde a la parte del exponente de la expresión de la iteración
            //Control de las partes de las expresiones
            numerador = pow(x,exponente); //Se obtiene el exponente de la iteración 
            denominador = factorial(exponente); //Se obtiene el facotrial del exponente en el denominador, ya que es el mismo
            denominador = div_t(denominador); //Se obtiene el inverso del exponente, ya que no se puede usar la división
            s_k = s_k + (pow(-1,k) * numerador * denominador); //Se obtiene el valor sk de la iteración para el método
            signo = pow(-1,k + 1); //Corresponde a la parte del -1 elevado al contador de la iteración
            exponente = 2 * (k + 1); //Corresponde a la parte del exponente de la expresión de la iteración
            //Control de las partes de las expresiones
            numerador = pow(x,exponente); //Se obtiene el exponente de la iteración 
            denominador = factorial(exponente); //Se obtiene el facotrial del exponente en el denominador, ya que es el mismo
            denominador = div_t(denominador); //Se obtiene el inverso del exponente, ya que no se puede usar la división
            s_k_1 = s_k + (pow(-1,k) * numerador * denominador); //Se obtiene el valor sk+1 de la iteración para el método
            error = abs(s_k_1 - s_k); //Se obtiene el valor del error para el método
            //Si el error del método supera a la tolerancia permitida
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
        //El método está dividido en tres secciones las cuales se separan
        //en una sección estática y dos iterativas
        //para mejor legibilidad del código se divide en tres partes
        //Sección estática de la izquierda dada como 2(x-1) / (x+1) 
        //Se nota que no se puede utilizar la división
        cpp_bin_float_50 seccion_izquierda; //LLeva el control de la parte izquierda de la funcion
        //La sección del centro corresponde a 1 / (2k +1)
        //Se nota que no se puede utilizar la división
        cpp_bin_float_50 seccion_centro; //LLeva el control de la sección central iterativa
        //La sección de la derecha iteratica corresponde a (x-1 / x+1)  ^ 2*k
        cpp_bin_float_50 seccion_derecha; //Lleva el control de la sección derecha iterativa
        cpp_bin_float_50 iteracion_a = 0; //Controlarel resultado iterativo para sk
        cpp_bin_float_50 iteracion_b = 0; //Controla el resultado iterativo para sk1
        cpp_bin_float_50 sk; //Llamada sk del método
        cpp_bin_float_50 sk1; //Llmada sk1 del método
        cpp_bin_float_50 error; //Muestra el error obtenido por el método del logaritmo natural
        cpp_bin_float_50 resultado_ln; //Muestra el valor del logaritmo natural del método
        //Se revisa si el dato ingresado no sea menor igual que cero
        if (x <= 0) {
            cout << "No se puede proceder con la operación el argumento es inválido" << endl;
            return 0;
        }
        //Se accede al ciclo iterativo para la ejecución del método
        for (int k = 0; k < iterMax; k++) {
            //Primera llamada iterativa s_k
            //Se ejecuta la sección del centro del método 
            seccion_centro = div_t(2*k + 1);
            //Se ejecuta la seccion derecha del método
            seccion_derecha = pow( ( (x-1)  * div_t(x+1) ), 2*k) ;
            //Se concatenan ambas secciones iterativas
            iteracion_a = iteracion_a + (seccion_centro * seccion_derecha);
            //Se ejecuta la sección de la izquierda
            seccion_izquierda = ( 2*(x - 1) ) * div_t(x + 1);
            sk = seccion_izquierda * iteracion_a; //Se llama a la primera llamada del método
            //Segunda llamada iterativa al método s_k_1
            //Se ejecuta la sección del centro del método 
            seccion_centro = div_t( (2*k + 1 ) + 1);
            //Se ejecuta la seccion derecha del método
            seccion_derecha = pow( ( (x-1)  * div_t(x+1) ), 2* ( k + 1 ) );
            //Se concatenan ambas secciones iterativas
            iteracion_b = iteracion_a + (seccion_centro * seccion_derecha);
            //Se ejecuta la sección de la izquierda
            seccion_izquierda = ( 2* (x - 1) ) * div_t(x + 1);
            sk1 = seccion_izquierda * iteracion_a; //Se llama a la primera llamada del método
            error = abs(sk1 - sk);//Se calcular el error obtenido por el método
            //Si el error es mayor que la tolerancia del método
            if (error < tol) {
                resultado_ln = sk1; //Se devuelve el resultado de la última llamada 
                break;
            }
        }
        return resultado_ln; //Se devuelve el resultado del logaritmo natural para el método
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

    /**
     * @param x
     * @return
     */
    int cosh_t(string x){
        int result = 0;
        return result;
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
            x_k_1 = x_k - ( funcion_cmpl( x_k,p, x ) * div_t(derivada( x_k, p)  ) );
            error = abs((x_k_1 - x_k) * div_t(x_k_1)); //Se cálculo el error asociado al métod
            //Si el error se pasa de la tolerancia
            if (error < tol) {
                resultado = x_k_1;  //Se devuelve el resultado con la última iteración
            }
            x_k = x_k_1;  //Se asigna la siguiente iteración
        }
        return resultado; //Se devuelve el valor de la iteración
}
    }

    /**
     * @param x
     * @return
     */
    int asin_t(string x){
        int result = 0;
        return result;
    }

};

int main(){
    
}


