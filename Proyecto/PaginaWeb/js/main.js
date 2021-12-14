var car1 = document.getElementById('carro1');
var car2 = document.getElementById('carro2');
//Controlar el carro 1
var x_car1 = 0;
var y_car1 = 0;
//Controlar el carro 2
var x_car2 = 0;
var y_car2 = 0;
//Click de prueba
car1.addEventListener('click', bruteSolution);

//Mover los carros
function moveCar1(x1, y1){
    if (x_car1 <= 85 && x_car1 >= 0) { //condición para que se mueva entre estos valores de la pantalla
        x_car1 = x_car1 + x1; //movimiento del valor x
        car1.style.left = x_car1 + "%"; //aplicar el valor obtenido al left del elemento
    }
    else { //si no cumple la condición, es decir, se sale de los valores de la pantalla, vuelve a empezar
        x_car1=0; //posicion inicial
        car1.style.left = x_car1 + "%"; //volvemos a aplicar el valor obtenido al left del elemento
    }
    if (abs(y_car1) <= 85 && abs(y_car1) >= 0) { //condición para que se mueva entre estos valores de la pantalla
        y_car1 = y_car1 + y1; //movimiento del valor x
        car1.style.top = y_car1 + "%"; //aplicar el valor obtenido al left del elemento
    }
    else { //si no cumple la condición, es decir, se sale de los valores de la pantalla, vuelve a empezar
        y_car1=0; //posicion inicial
        car1.style.top = y_car1 + "%"; //volvemos a aplicar el valor obtenido al left del elemento
    }
}
function moveCar2(x1, y1){
    if (x_car2 <= 85 && x_car2 >= 0) { //condición para que se mueva entre estos valores de la pantalla
        x_car2 = x_car2 + x1; //movimiento del valor x
        car2.style.left = x_car2 + "%"; //aplicar el valor obtenido al left del elemento
    }
    else { //si no cumple la condición, es decir, se sale de los valores de la pantalla, vuelve a empezar
        x_car2=0; //posicion inicial
        car2.style.left = x_car2 + "%"; //volvemos a aplicar el valor obtenido al left del elemento
    }
    if (abs(y_car2) <= 85 && abs(y_car2) >= 0) { //condición para que se mueva entre estos valores de la pantalla
        y_car2 = y_car2 + y1; //movimiento del valor x
        car2.style.top = y_car2 + "%"; //aplicar el valor obtenido al left del elemento
    }
    else { //si no cumple la condición, es decir, se sale de los valores de la pantalla, vuelve a empezar
        y_car2=0; //posicion inicial
        car2.style.top = y_car2 + "%"; //volvemos a aplicar el valor obtenido al left del elemento
    }
}
function abs(x){return (x < 0) ? -1*x : x;}

//Sleep para que se vea animado
function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}
//Animar los carros
async function animateCar1(x1, y1) {
    for (let i = 0; i < 5; i++) {
        moveCar1(x1, y1);
        await sleep(100);
    }
}
async function wait(i) {
    if(i >= 5){
        await sleep(3000);
        animateCar1(1, 1);
        return;
    }
    //animateCar1(1, -1);
    await sleep(300);
    animateCar1(1, 0);
    wait(i+1);
}
async function animateCar2(x1, y1) {
    for (let i = 0; i < 20; i++) {
        moveCar2(x1, y1);
        await sleep(100);
    }
}

//solucion bruta
var a = [[8, 10, 4, 5, 9], [9, 6, 7, 5, 6]]; // t de las estaciones
var t = [[2, 3, 1, 3], [2, 1, 2, 2]]; // cambio de estacion
var e = [3, 5];                              // entrada a la linea
var x = [2, 1];  
function bruteSolution(){
    animateCar1(1, -1)
    wait(0);
}

function productionLines(i, camino, linea) {
    if(i >= 5){
        animateCar1(0, 1);
        return;
    }
    animateCar1(1, 0);
    //solcion en quedate
    //traemos un carro n+1
    //Cambiamos de linea
    //solucion en cambiate
    productionLines(i+1);
}
