var car1 = document.getElementById('carro1');
var car2 = document.getElementById('carro2');
var car3 = document.getElementById('carro3');
var car4 = document.getElementById('carro4');
var car5 = document.getElementById('carro5');
var car6 = document.getElementById('carro6');
var car7 = document.getElementById('carro7');
var car8 = document.getElementById('carro8');
//Controlar el carro 1
var x_car1 = 0;
var y_car1 = 0;
//Controlar el carro 2
var x_car2 = 0;
var y_car2 = 0;
//Controlar el carro 3
var x_car3 = 0;
var y_car3 = 0;
//Controlar el carro 4
var x_car4 = 0;
var y_car4 = 0;
//Controlar el carro 5
var x_car5 = 0;
var y_car5 = 0;
//Controlar el carro 6
var x_car6 = 0;
var y_car6 = 0;
//Controlar el carro 7
var x_car7 = 0;
var y_car7 = 0;
//Controlar el carro 8
var x_car8 = 0;
var y_car8 = 0;


//Click de prueba
document.getElementById('demo').addEventListener('click', dpSolution);
//car8.addEventListener('click', bruteSolution);

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
function moveCar3(x1, y1){
    if (x_car3 <= 85 && x_car3 >= 0) { //condición para que se mueva entre estos valores de la pantalla
        x_car3 = x_car3 + x1; //movimiento del valor x
        car3.style.left = x_car3 + "%"; //aplicar el valor obtenido al left del elemento
    }
    else { //si no cumple la condición, es decir, se sale de los valores de la pantalla, vuelve a empezar
        x_car3=0; //posicion inicial
        car3.style.left = x_car3 + "%"; //volvemos a aplicar el valor obtenido al left del elemento
    }
    if (abs(y_car3) <= 85 && abs(y_car3) >= 0) { //condición para que se mueva entre estos valores de la pantalla
        y_car3 = y_car3 + y1; //movimiento del valor x
        car3.style.top = y_car3 + "%"; //aplicar el valor obtenido al left del elemento
    }
    else { //si no cumple la condición, es decir, se sale de los valores de la pantalla, vuelve a empezar
        y_car3=0; //posicion inicial
        car3.style.top = y_car3 + "%"; //volvemos a aplicar el valor obtenido al left del elemento
    }
}
function moveCar4(x1, y1){
    if (x_car4 <= 85 && x_car4 >= 0) { //condición para que se mueva entre estos valores de la pantalla
        x_car4 = x_car4 + x1; //movimiento del valor x
        car4.style.left = x_car4 + "%"; //aplicar el valor obtenido al left del elemento
    }
    else { //si no cumple la condición, es decir, se sale de los valores de la pantalla, vuelve a empezar
        x_car4=0; //posicion inicial
        car4.style.left = x_car4 + "%"; //volvemos a aplicar el valor obtenido al left del elemento
    }
    if (abs(y_car4) <= 85 && abs(y_car4) >= 0) { //condición para que se mueva entre estos valores de la pantalla
        y_car4 = y_car4 + y1; //movimiento del valor x
        car4.style.top = y_car4 + "%"; //aplicar el valor obtenido al left del elemento
    }
    else { //si no cumple la condición, es decir, se sale de los valores de la pantalla, vuelve a empezar
        y_car4=0; //posicion inicial
        car4.style.top = y_car4 + "%"; //volvemos a aplicar el valor obtenido al left del elemento
    }
}
function moveCar5(x1, y1){
    if (x_car5 <= 85 && x_car5 >= 0) { //condición para que se mueva entre estos valores de la pantalla
        x_car5 = x_car5 + x1; //movimiento del valor x
        car5.style.left = x_car5 + "%"; //aplicar el valor obtenido al left del elemento
    }
    else { //si no cumple la condición, es decir, se sale de los valores de la pantalla, vuelve a empezar
        x_car5=0; //posicion inicial
        car5.style.left = x_car5 + "%"; //volvemos a aplicar el valor obtenido al left del elemento
    }
    if (abs(y_car5) <= 85 && abs(y_car5) >= 0) { //condición para que se mueva entre estos valores de la pantalla
        y_car5 = y_car5 + y1; //movimiento del valor x
        car5.style.top = y_car5 + "%"; //aplicar el valor obtenido al left del elemento
    }
    else { //si no cumple la condición, es decir, se sale de los valores de la pantalla, vuelve a empezar
        y_car5=0; //posicion inicial
        car5.style.top = y_car5 + "%"; //volvemos a aplicar el valor obtenido al left del elemento
    }
}
function moveCar6(x1, y1){
    if (x_car6 <= 85 && x_car6 >= 0) { //condición para que se mueva entre estos valores de la pantalla
        x_car6 = x_car6 + x1; //movimiento del valor x
        car6.style.left = x_car6 + "%"; //aplicar el valor obtenido al left del elemento
    }
    else { //si no cumple la condición, es decir, se sale de los valores de la pantalla, vuelve a empezar
        x_car6=0; //posicion inicial
        car6.style.left = x_car6 + "%"; //volvemos a aplicar el valor obtenido al left del elemento
    }
    if (abs(y_car6) <= 85 && abs(y_car6) >= 0) { //condición para que se mueva entre estos valores de la pantalla
        y_car6 = y_car6 + y1; //movimiento del valor x
        car6.style.top = y_car6 + "%"; //aplicar el valor obtenido al left del elemento
    }
    else { //si no cumple la condición, es decir, se sale de los valores de la pantalla, vuelve a empezar
        y_car6=0; //posicion inicial
        car6.style.top = y_car6 + "%"; //volvemos a aplicar el valor obtenido al left del elemento
    }
}
function moveCar7(x1, y1){
    if (x_car7 <= 85 && x_car7 >= 0) { //condición para que se mueva entre estos valores de la pantalla
        x_car7 = x_car7 + x1; //movimiento del valor x
        car7.style.left = x_car7 + "%"; //aplicar el valor obtenido al left del elemento
    }
    else { //si no cumple la condición, es decir, se sale de los valores de la pantalla, vuelve a empezar
        x_car7=0; //posicion inicial
        car7.style.left = x_car7 + "%"; //volvemos a aplicar el valor obtenido al left del elemento
    }
    if (abs(y_car7) <= 85 && abs(y_car7) >= 0) { //condición para que se mueva entre estos valores de la pantalla
        y_car7 = y_car7 + y1; //movimiento del valor x
        car7.style.top = y_car7 + "%"; //aplicar el valor obtenido al left del elemento
    }
    else { //si no cumple la condición, es decir, se sale de los valores de la pantalla, vuelve a empezar
        y_car7=0; //posicion inicial
        car7.style.top = y_car7 + "%"; //volvemos a aplicar el valor obtenido al left del elemento
    }
}
function moveCar8(x1, y1){
    if (x_car8 <= 85 && x_car8 >= 0) { //condición para que se mueva entre estos valores de la pantalla
        x_car8 = x_car8 + x1; //movimiento del valor x
        car8.style.left = x_car8 + "%"; //aplicar el valor obtenido al left del elemento
    }
    else { //si no cumple la condición, es decir, se sale de los valores de la pantalla, vuelve a empezar
        x_car8=0; //posicion inicial
        car8.style.left = x_car8 + "%"; //volvemos a aplicar el valor obtenido al left del elemento
    }
    if (abs(y_car8) <= 85 && abs(y_car8) >= 0) { //condición para que se mueva entre estos valores de la pantalla
        y_car8 = y_car8 + y1; //movimiento del valor x
        car8.style.top = y_car8 + "%"; //aplicar el valor obtenido al left del elemento
    }
    else { //si no cumple la condición, es decir, se sale de los valores de la pantalla, vuelve a empezar
        y_car8=0; //posicion inicial
        car8.style.top = y_car8 + "%"; //volvemos a aplicar el valor obtenido al left del elemento
    }
}

function returnToStart(car){
    if(car == 1){
        car1.style.left = 0 + "%";
    }
    else if(car == 2){
        car2.style.left = 0 + "%";
    }
    else if(car == 3){
        car3.style.left = 0 + "%";
    }
    else if(car == 4){
        car4.style.left = 0 + "%";
    }
    else if(car == 5){
        car5.style.left = 0 + "%";
    }
    else if(car == 6){
        car6.style.left = 0 + "%";
    }
    else if(car == 7){
        car7.style.left = 0 + "%";
    }
    else if(car == 8){
        car8.style.left = 0 + "%";
    }
}
function abs(x){return (x < 0) ? -1*x : x;}

//Sleep para que se vea animado
function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}
//Animar los carros
async function animateCar(x1, y1, ncar) {
    for (let i = 0; i < 20; i++) {
        if(ncar == 1){
            moveCar1(x1, y1);
        }
        else if(ncar == 2){
            moveCar2(x1, y1);
        }
        else if(ncar == 3){
            moveCar3(x1, y1);
        }
        else if(ncar == 4){
            moveCar4(x1, y1);
        }
        else if(ncar == 5){
            moveCar5(x1, y1);
        }
        else if(ncar == 6){
            moveCar6(x1, y1);
        }
        else if(ncar == 7){
            moveCar7(x1, y1);
        }
        else if(ncar == 8){
            moveCar8(x1, y1);
        }
        await sleep(100);
    }
}
function bringCar(car){
    if(x_car1 == 0){
        return 1;
    }
    else if(x_car2 == 0){
        car2.style.left = getXcar(car) + "%";
        car2.style.top = getYcar(car) + "%";
        x_car2 = getXcar(car);
        y_car2 = getYcar(car);
        return 2;
    }
    else if(x_car3 == 0){
        car3.style.left = getXcar(car) + "%";
        car3.style.top = getYcar(car) + "%";
        x_car3 = getXcar(car);
        y_car3 = getYcar(car);
        return 3;
    }
    else if(x_car4 == 0){
        car4.style.left = getXcar(car) + "%";
        car4.style.top = getYcar(car) + "%";
        x_car4 = getXcar(car);
        y_car4 = getYcar(car);
        return 4;
    }
    else if(x_car5 == 0){
        car5.style.left = getXcar(car) + "%";
        car5.style.top = getYcar(car) + "%";
        x_car5 = getXcar(car);
        y_car5 = getYcar(car);
        return 5;
    }
    else if(x_car6 == 0){
        car6.style.left = getXcar(car) + "%";
        car6.style.top = getYcar(car) + "%";
        x_car6 = getXcar(car);
        y_car6 = getYcar(car);
        return 6;
    }
    else if(x_car7 == 0){
        car7.style.left = getXcar(car) + "%";
        car7.style.top = getYcar(car) + "%";
        x_car7 = getXcar(car);
        y_car7 = getYcar(car);
        return 7;
    }
    else if(x_car8 == 0){
        car8.style.left = getXcar(car) + "%";
        car8.style.top = getYcar(car) + "%";
        x_car8 = getXcar(car);
        y_car8 = getYcar(car);
        return 8;
    }
}
function getXcar(car){
    if(car == 1){
        return x_car1;
    }
    if(car == 2){
        return x_car2;
    }
    if(car == 3){
        return x_car3;
    }
    if(car == 4){
        return x_car4;
    }
    if(car == 5){
        return x_car5;
    }
    if(car == 6){
        return x_car6;
    }
    if(car == 7){
        return x_car7;
    }
    if(car == 8){
        return x_car8;
    }
}
function getYcar(car){
    if(car == 1){
        return y_car1;
    }
    if(car == 2){
        return y_car2;
    }
    if(car == 3){
        return y_car3;
    }
    if(car == 4){
        return y_car4;
    }
    if(car == 5){
        return y_car5;
    }
    if(car == 6){
        return y_car6;
    }
    if(car == 7){
        return y_car7;
    }
    if(car == 8){
        return y_car8;
    }
}

var a = [[8,10,4], [9,6,7]];
var t = [[0,2,3], [0,2,1]];
var e = [3,5], x = [2,1];
async function wait() {
    var first, second, up, down;
    var currentCar1 = 1, currentCar2 = 5, toDelete;
    first = e[0] + a [0][0];
    animateCar(1, -0.2, 1);
    second = e[1] + a[1][0];
    animateCar(1, 0.2, 5);
    for(let i = 1; i < 3; i++){
        await sleep(3000);
        up = min(first + a[0][i], second + t[1][i] + a[0][i]);
	    down = min(second + a[1][i], first + t[0][i] + a[1][i]);
        if(up == first + a[0][i] && down == second + a[1][i])
        {
            animateCar(1, 0, currentCar1);
            animateCar(1, 0, currentCar2);
        }
        else if(up == second + t[1][i] + a[0][i] && down == second + a[1][i])
        {
            toDelete = currentCar1;
            currentCar1 = bringCar(currentCar2);
            returnToStart(toDelete);
            animateCar(1, -2.2, currentCar1);
            animateCar(1, 0, currentCar2);
        }
        else if(up == first + a[0][i] && down == first + t[0][i] + a[1][i])
        {
            toDelete = currentCar2;
            currentCar2 = bringCar(currentCar1);
            returnToStart(toDelete);
            animateCar(1, 0, currentCar1);
            animateCar(1, 2.2, currentCar2);
        }
        else if(up == first + a[0][i] && down == first + t[0][i] + a[1][i]){
            var aux = currentCar1;
            var toDelete2 = currentCar2;
            currentCar1 = bringCar(currentCar2);
            currentCar2 = bringCar(aux);
            returnToStart(aux);
            returnToStart(toDelete2);
            animateCar(1, -2.2, currentCar1);
            animateCar(1, 2.2, currentCar2);
        }
        first = up;
	second = down;
    }
    await sleep(3000);
    animateCar(1, 0.4, currentCar1);
    
    animateCar(1, -0.4, currentCar2);
    await sleep(3000);
    return (min(first + e[0], second + e[1]));
}
function min(a, b){
    return (a <= b) ? a : b;
}
//solucion bruta

async function dpSolution(){
    var result = wait();
    console.log(result);
}
