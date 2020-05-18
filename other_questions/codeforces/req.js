function foo(a) {
    for (var i = 0; i < a.length; i++) {
        var r = Math.floor(Math.random() * (i + 1));
        var t = a[i];
        a[i] = a[r];
        a[r] = t;
    }
    return a;
}

function arrayReduce(array, iteratee, initAccum) {
    var index = -1, length = array.length, accumulator = initAccum;
    while (++index < length) {
    accumulator = iteratee(accumulator, array[index]);
    }
    return accumulator;
}

a = [1, 2, 3, 4, 5]
console.log(foo(a))