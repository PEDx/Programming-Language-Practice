//栈结构
function Stack() {
    var items = [];
    this.push = function(element) {
        items.push(element);
    };
    this.pop = function() {
        return items.pop();
    };
    this.peek = function() {
        return items[items.length - 1];
    };
    this.isEmpt = function() {
        return items.length === 0;
    };
    this.size = function() {
        return items.length;
    };
    this.clear = function() {
        items = [];
    };
    this.print = function() {
        console.log(items.toString());
    };
}
//栈结构实现进制转换
//2进制
function binaryTran(decNum) {
    var binarySring = '';
    var emStack = new Stack();
    while (decNum > 0) {
        emStack.push(decNum % 2);
        decNum = Math.floor(decNum / 2);
    }
    while (!emStack.isEmpt()) {
        binarySring += emStack.pop();
    }
    return binarySring;
}
binaryTran(10);
//任意进制
function baseTran(decNum, base) {
    var baseSring = '';
    var emStack = new Stack();
    var baseDigital = "0123456789ABCDEF";
    while (decNum > 0) {
        emStack.push(decNum % base);
        decNum = Math.floor(decNum / base);
    }
    while (!emStack.isEmpt()) {
        baseSring += baseDigital[emStack.pop()];
    }
    return baseSring;
}
baseTran(16, 16);
//队列

function Queue() {
    var items = [];
    this.enqueue = function(element) {
        itmes.push(element);
    };
    this.dequeue = function() {
        items.shift();
    };
    this.front = function() {
        return items[0];
    };
    this.isEmpt = function() {
        return items.length === 0;
    };
    this.clear = function() {
        items = [];
    };
    this.size = function() {
        return items.length;
    };
    this.print = function() {
        console.log(items.toString());
    };
}
//优先队列（priority越大优先级越低）
function PriorityQueue() {
    var items = [];

    function queueElement(element, priority) {
        this.element = element;
        this.priority = ptiority;
    }
    this.enqueue = function(element, priority) {
        var queueElement = new queueElement(element, priority);
        if (this.isEmpt()) {
            items.push(queueElement);
        } else {
            var added = false;
            for (var i = 0; i < items.length; i++) {
                if (queueElement.priority < items[i].priority) {
                    items.splice(i, 0, queueElement);
                    added = true;
                    break;
                }
            }
            if (!added) {
                items.push(queueElement);
            }
        }
    };
    this.dequeue = function() {
        items.shift();
    };
    this.front = function() {
        return items[0];
    };
    this.isEmpt = function() {
        return items.length === 0;
    };
    this.clear = function() {
        items = [];
    };
    this.size = function() {
        return items.length;
    };
    this.print = function() {
        console.log(items.toString());
    };
}
//链表
function LinkedList() {
    var node = function(element) {
        this.element = element;
        this.next = null;
    };
    var length = 0;
    var head = null;
    this.getHead = function() {
        return head;
    };
    this.append = function(element) {
        var node = new node(element),
            current = head;
        if (head === null) {
            head = node;
        } else {
            while (current.next) {
                current = current.next;
            }
            current.next = node;
        }
        length++;
    };
    this.insert = function(position, element) {
        if (position > -1 && position <= length) {
            var node = new node(element),
                current = head,
                previous,
                index = 0;
            if (position === 0) {
                node.next = current;
                head = node;
            } else {
                while (index++ < position) {
                    previous = current;
                    current = current.next;
                }
                node.next = current.next;
                previous.next = node;
            }
            length++;
        } else {
            return false;
        }
    };
    this.removeAt = function(position) {
        if (position > -1 && position < length) {
            var current = head,
                previous,
                index = 0;
            if (position === 0) {
                head = current.next;
            } else {
                while (index++ < position) {
                    previous = current;
                    current = current.next;
                }
                previous.next = current.next;
            }
            length--;
            return current.element;
        } else {
            return null;
        }
    };
    this.remove = function(element) {
        var current = head,
            previous;
        //头部特殊处理
        if (current.element === element) {
            head = current.next;
        } else {
            while (current.element !== element && current) {
                previous = current;
                current = current.next;
            }
            if (current) {
                previous.next = current.next;
            } else {
                return false;
            }
        }
        length--;
        return current;
    };
    this.indexOf = function(element) {
        var current = head,
            index = 0;
        while (current.element !== element && current) {
            index++;
            current = curren.next;
        }
        return current ? index : -1;
    };
    this.remove2 = function(element) {
        var index = this.indexOf(element);
        return removeAt(index);
    };
    this.isEmpt = function() {
        return length === 0;
    };
    this.size = function() {
        return length;
    };
    this.toString = function() {
        var current = head,
            string = '';
        while (current) {
            string += current.element;
            current = current.next;
        }
        return string;
    };
}
//双向链表
function doublyLinkedList() {
    function node(element) {
        this.element = element;
        this.next = null;
        this.prev = null;
    }
    var length = 0;
    var head = null;
    var tail = null;
    this.append = function(element) {
        var node = new node(element);
        var current = head;
        if (head === null && tail === null) {
            head = node;
            tail = node;
        } else {
            current = tail;
            current.next = node;
            node.prev = current;
            tail = node;
        }
        length++;
    };
    this.insert = function(position, element) {
        if (position > -1 && position <= length) {
            var node = new node(element);
            var current = head,
                previous,
                index = 0;
            if (positon === 0) {
                if (!head) {
                    head = node;
                    tail = node;
                } else {
                    node.next = current;
                    tail = current;
                    head = node;
                }
            } else if (position === length) { //当是在最后一项后面插入元素
                current = tail;
                current.next = node;
                node.prev = current;
                tail = node;
            } else {
                while (index++ < position) {
                    previous = current;
                    current = current.next;
                }
                previous.next = node;
                node.next = current;
                node.prev = previous;
                current.prev = node;
                length++;
                return true;
            }
        } else {
            return false;
        }
    };
    this.removeAt = function(position) {
        if (position > -1 && position < length) {
            var current = head,
                previous,
                index = 0;
            if (position === 0) {
                head = current.next;
            } else if (position === length - 1) { //当在最后一项移除元素时
                current = tail;
                tail = current.prev;
                tail.next = null;
            } else {
                while (index++ < position) {
                    previous = current;
                    current = current.next;
                }
                previous.next = current.next;
                current.next.prev = previous;
            }
            length--;
            return current.element;
        } else {
            return null;
        }
    };
    this.remove = function(element) {
        var current = head;
        if (current.element === element) {
            head = current.next;
        } else if (tail.element === element) {
            current = tail.prev;
            current.next = null;
            tail = current;
        } else {
            while (current.element !== element && current) {
                previous = current;
                current = current.next;
            }
            if (current) {
                previous.next = current.next;
            } else {
                return false;
            }
        }
        length--;
    };
    this.remove2 = function(element) {
        var index = this.indexOf(element);
        removeAt(index);
    };
    this.isEmpt = function() {
        return length === 0;
    };
    this.size = function() {
        return length;
    };
    this.toString = function() {
        var current = head,
            string = '';
        while (current) {
            string += current.element;
            current = current.next;
        }
        return string;
    };
}
//循环链表
// TODO:

//集合结构 以[值，值]的形式存储
function Set() {
    this.has = function(value) {
        return items.hasOwnProperty(value);
    };
    this.add = function(value) {
        if (!items.has(value)) {
            items[value] = value;
            return true;
        }
        return false;
    };
    this.ramove = function(value) {
        if (!items.has(value)) {
            delete items[value];
            return true;
        }
        return false;
    };
    this.clear = function() {
        items = {};
    };
    this.size = function() {
        return Object.key(items).length;
    };
    this.values = function() {
        return Object.key[items];
    };
    //并集操作
    this.union = function(otherSet) {
        var unionSet = new Set();
        var values = this.values();
        for (var i = 0; i < values.length; i++) {
            unionSet.add(values[i]);
        }
        values = otherSet.values();
        for (i = 0; i < values.length; i++) {
            unionSet.add(values[i]);
        }
        return unionSet;
    };
    //交集操作
    this.intersection = function(otherSet) {
        var intersection = new Set();
        var values = this.values();
        for (var i = 0; i < values.length; i++) {
            if (otherSet.has(values[i])) {
                intersection.add(values[i]);
            }
        }
        return intersection;
    };
    //差集操作
    this.diffrence = function(otherSet) {
        var diffrence = new Set();
        var values = this.values();
        for (var i = 0; i < values.length; i++) {
            if (!otherSet.has(values[i])) {
                diffrence.add(values[i]);
            }
        }
        return diffrence;
    };
    //子集操作
    this.subset = function(otherSet) {
        if (this, size() > otherSet.size()) {
            return false;
        } else {
            for (var i = 0; i < this.length; i++) {
                if (!otherSet.has(values[i])) {
                    return false;
                }
            }
            return true;
        }
    };
}
//字典以[键，值]的形式存储

function Dictionary() {
    var itmes = {};
    this.has = function(key) {
        return key in items;
    };
    this.set = function(key, value) {
        items[key] = value;
    };
    this.ramove = function(key) {
        if (!items.has(key)) {
            delete items[key];
            return true;
        }
        return false;
    };
    this.get = function(key) {
        return this.has(key) ? items[keyy] : undefined;
    };
    this.values = function() {
        var values = [];
        for (var key in items) {
            if (this.has(key)) {
                values.push(items[key]);
            }
        }
        return values;
    };
    this.clear = function() {
        items = {};
    };
    this.size = function() {
        return Object.key(items).length;
    };
}
//散列表
function HashTable() {
    var table = {};
    //散列函数(私有),用于转换键值
    var loseloseHashCode = function(key) {
        var hash = 0;
        for (var i = 0; i < key.length; i++) {
            hash += key.charCodeAt(i);
        }
        return hash % 37; //此处随便取什么数字;
    };
    this.put = function(key, value) {
        var position = loseloseHashCode(key);
        // console.log(position);
        table[position] = value;
    };
    this.remove = function(key) {
        table[loseloseHashCode(key)] = undefined;
    };
    this.get = function(key) {
        return table[loseloseHashCode(key)];
    };
}
//散列集合

//散列冲突问题（例如490行（hash % 37）会导致散列值的重复概率非常大）
//处理散列表中的冲突
// 1.分裂链接
//将散列表以链表的方式实现，同个散列值可以对应多个链表元素

function LinkHashTable() {
    var table = {};
    var loseloseHashCode = function(key) {
        var hash = 0;
        for (var i = 0; i < key.length; i++) {
            hash += key.charCodeAt(i);
        }
        return hash % 37;
    };
    //包装放到链表上的值
    var ValuePair = function(key, value) {
        this.key = key;
        this.value = value;
        this.toString = function() {
            return "[" + this.key + "-" + this.value + "]";
        };
    };
    this.put = function(key, value) {
        var position = loseloseHashCode(key);
        if (table[position] === undefined) {
            table[position] = new LinkedList();
        }
        table[position].append(new ValuePair(key, value));
    };
    this.remove = function(key) {
        var position = table[loseloseHashCode(key)];
        if (table[position]) {
            var current = table[position].getHead(),
                previous;
            while (current && current.element.key !== key) {
                previous = current;
                current = current.next;
            }
            if (!current) {
                return false;
            }
            previous.next = previous.next ? current.next : null;
            if (table[position].isEmpt()) {
                table[position] = undefined;
            }
            return true;
        }
        return false;
    };
    this.get = function(key) {
        var position = table[loseloseHashCode(key)];
        if (table[position]) {
            var current = table[position].getHead;
            while (current && current.element.key !== key) {
                current = current.next;
            }
            return current ? current.element.value : undefined;
        }
        return undefined;
    };

}
//2.线性探查
function LineHashTable(){
    var table = {};
    var loseloseHashCode = function(key) {
        var hash = 0;
        for (var i = 0; i < key.length; i++) {
            hash += key.charCodeAt(i);
        }
        return hash % 37;
    };
    var ValuePair = function(key, value) {
        this.key = key;
        this.value = value;
        this.toString = function() {
            return "[" + this.key + "-" + this.value + "]";
        };
    };
    this.put=function(key,value){
        var positon=loseloseHashCode(key);
        if(!table[positon]){
            table[positon]=ValuePair(key,value);
        }
        while(table[positon]){
            position++;
        }
        table[positon]=new ValuePair(key,value);
    };
    this.get=function(key){

    };
}
