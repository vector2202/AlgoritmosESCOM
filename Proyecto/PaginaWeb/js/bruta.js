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
document.getElementById('demo').addEventListener('click', bruteSolution);
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
async function wait(i, car, linea) {
    await sleep(3000);
    if(i >= 2){
        if(linea < 2){
            animateCar(1, 0.4, car);
        }
        else{
            animateCar(1, -0.4, car);
        }  
        return;
    }
    var nextCar = bringCar(car);
    animateCar(1, 0, car);
    wait(i+1, car, linea);
    await sleep(3000);
    if(linea < 2){
        animateCar(1, 2.2, nextCar);
    }
    else{
        animateCar(1, -2.2, nextCar);
    }
    wait(i+1, nextCar, (linea < 2) ? 2 : 1);
}
function min(a, b){
    return (a <= b) ? a : b;
}
//solucion bruta
var a = [[8,10,4], [9,6,7]];
var t = [[0,2,3], [0,2,1]];
var e = [3,5], x = [2,1];
async function bruteSolution(){
    animateCar(1, -0.2, 1);
    wait(0, 1, 1);
    await sleep(15000);
    animateCar(1, 0.2, 5);
    wait(0, 5, 2);
    console.log(min(solbruta(0, e[0], 0), solbruta(0, e[1], 1)));
}
function solbruta(i, camino, linea) {
    if (i >= 3){
        return camino + x[linea];
    }
    var quedarse = 0, cambiarse = 0;
    // nos quedamos en la linea
    quedarse = solbruta(i + 1, camino + a[linea][i], linea);
    // nos cambiamos de linea
    cambiarse = solbruta(i + 1, camino + t[linea][i] + a[linea][i],
              (linea == 0) ? 1 : 0);
    return min(quedarse, cambiarse);
}
