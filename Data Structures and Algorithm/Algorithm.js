//常见排序算法及其他
// Merry Christmas Mr.Lawrence


//斐波那契数列缓存尾递归算法
// var count=0;核心函数跑了多少次
var fib=(function (){
    var cache=[];
    return function fib_cache(n){
        if(cache[n]) return cache[n-1];
        function fib_itm(a, b, n) {
            // count++;
            if (n === 0) return b;
            cache.push(a+b);
            return fib_itm(b, a + b, n - 1);
        }
        return fib_itm(1, 0, n);
    };
})();
fib(50);
// console.log(count);
