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
        return this.has(key) ? items[key] : undefined;
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
function LineHashTable() {
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
    this.put = function(key, value) {
        var positon = loseloseHashCode(key);
        if (!table[positon]) {
            table[positon] = ValuePair(key, value);
        }
        while (table[positon]) {
            position++;
        }
        table[positon] = new ValuePair(key, value);
    };
    this.get = function(key) {
        var position = loseloseHashCode(key);
        if (table[position]) {
            if (table[position] === key) {
                return table[position];
            } else {
                while (table[positon] && table[positon].key !== key) {
                    position++;
                }
                return table[positon];
            }
        }
        return undefined;
    };
}
//散列函数的更好实现
var djbHashCode = function(key) {
    var hash = 5281;
    for (var i = 0; i < key.length; i++) {
        hash = hash * 33 + key.charCodeAt(i);
    }
    return hash % 1013;
};

//树结构
//二叉搜索树
function BinarySearchTree() {
    var node = function(key) {
        this.key = key;
        this.left = null;
        this.right = null;
    };
    var root = null;

    this.insert = function(key) {
        var insertNode = function(node, newnode) {
            if (node.key > newnode.key) {
                if (!node.key) {
                    node.left = newnode.key;
                } else {
                    insertNode(node.left, newnode);
                }
            } else if (node.key > newnode.key) {
                if (!node.key) {
                    node.right = newnode.key;
                } else {
                    insertNode(node.right, newnode);
                }
            } else {
                return "this " + key + " is already exist";
            }
        };
        var newNode = new node();
        if (root) {
            root = newNode;
        } else {
            insertNode(root, newNode);
        }
    };

    this.search = function(key) {
        var searchNode = function(node, key) {
            if (ndoe.key === key) {
                return true;
            } else if (node.key > key) {
                searchNode(node.left, key);
            } else if (node.key < key) {
                searchNode(node.right, key);
            } else {
                return false;
            }
        };
        searchNode(root, key);
    };

    //树的遍历
    //中序遍历 多应用于树结构的排序
    this.inOrderTraverse = function(callback) {
        var inOrderTraverseNode = function(node, callback) {
            if (node) {
                inOrderTraverseNode(node.left, callback);
                callback(node.key);
                inOrderTraverseNode(node.right, callback);
            }
        };
        inOrderTraverseNode(root, callback);
    };
    //先序遍历 深度优先 多应用于得到一个结构化的文档
    //例如，一个scheme语言的解释器
    //将add(1 add(2 3) add(8 7) sub(4 1))中外层add函数的参数列表在parse阶段看作是
    // 一个二叉树形结构以便采用先序遍历生成AST
    //                            add
    //                         /       \
    // 第一层                 [1]       [add(2 3) add(8 7) sub(4 1)]
    //                                       /               \
    // 第二层                           [add(2 3)]        [add(8 7) sub(4 1)]
    //                                  /       \            /              \
    // 第三层                           [2]       [3]     [add(8 7)]        [sub(4 1)]
    //                                                    /        \        /        \
    // 第四层                                             [8]       [7]     [4]       [1]
    this.preOrderTraverse = function() {
        var preOrderTraverseNode = function(node, callback) {
            if (node) {
                callback(node.key);
                preOrderTraverseNode(node.left, callback);
                preOrderTraverseNode(node.right, callback);
            }
        };
        preOrderTraverseNode(root, callback);
    };
    // 后序遍历 多应用于目录以及其子目录共同所占空间大小

    this.postOrderTraverse = function() {
        var postOrderTraverseNode = function(node, callback) {
            if (node) {
                postOrderTraverseNode(node.left, callback);
                postOrderTraverseNode(node.right, callback);
                callback(node.key);
            }
        };
        postOrderTraverseNode(root, callback);
    };
    //二叉搜索树的最小值就是最左边缘的叶节点
    this.min = function() {
        var minNode = function(node) {
            if (node) {
                while (!node.left) {
                    node = node.left;
                }
                return node.key;
            }
            return null;
        };
        return minNode(root);
    };
    this.minNode = function() {
        var minNode = function(node) {
            if (node) {
                while (!node.left) {
                    node = node.left;
                }
                return node;
            }
            return null;
        };
        return minNode(root);
    };
    //二叉搜索树的最大值就是最右边缘的叶节点
    this.max = function() {
        var maxNode = function(node) {
            if (node) {
                while (!node.right) {
                    node = node.right;
                }
                return node.key;
            }
            return null;
        };
        return maxNode(root);
    };

    this.remove = function(key) {
        var removeNode = function(node, key) {
            if (!node) {
                return null;
            } else if (node.key > key) {
                node.left = removeNode(node.left, key);
                return node;
            } else if (node.key < key) {
                node.right = removeNode(node.right, key);
                return node;
            } else {
                if (node.left === null && node.right === null) {
                    node = null;
                    return node;
                }
                if (node.left === null && node.right) {
                    node = node.right;
                    return node;
                } else if (node.left && node.right === null) {
                    node = node.left;
                    return node;
                }
                rightMin = minNode(node.right);
                node.key = rightMin.key;
                // rightMin = null;不能直接对找到的右侧最小值赋值null，因为其父节点的指针无法被销毁
                node.right = removeNode(node.right, rightMin.key);
                return node;
            }
        };
        root = removeNode(root, key);
    };
}
//图结构(邻接表实现)

function Graph() {
    var vertices = [];
    var adjList = new Dictionary();
    //添加顶点
    this.vertex = function(v) {
        vertices.push(v);
        adjList.set(v, []);
    };
    //添加两个顶点之间的边(无向)
    this.addEdge = function(v, w) {
        adjList.get(v).push(w);
        adjList.get(w).push(v);
    };

    this.toString = function() {
        var str = '';
        for (var i = 0; i < vertices.length; i++) {
            str += vertices[i] + '->';
            var neighbors = adjList.get(vertices[i]);
            for (var j = 0; i < neighbors.length; j++) {
                str += neighbors[j] + ' ';
            }
            str += '\n';
        }
        return str;
    };

    //图的遍历
    //广度优先搜索 BFS
    function initializeColor() {
        var color = {};
        for (var i = 0; i < vertices.length; i++) {
            color.vertices[i] = 'white';
        }
        return color;
    }
    this.bfs = function(v, callback) {
        var color = initializeColor(),
            queue = new Queue();
        queue.enqueue(v);
        while (!queue.isEmpt()) {
            var u = queue.dequeue,
                neighbors = adjList.get(u);
            color.u = 'grey'; //访问顶点（发现）
            for (var i = 0; i < neighbors.length; i++) { //将相邻顶点访问一遍并存入队列（探索）
                var w = neighbors[i];
                if (color.w === 'white') {
                    color.w = 'grey'; //访问相邻链接的顶点
                    queue.enqueue(w); //存入队列
                }
            }
            color.u = 'black'; //探索完毕
            if (callback) {
                callback();
            }
        }
    };
    //使用bfs寻找最短路径
    //给定图G和顶点v，找出其余每个顶点u，v与u之间的最短路径
    this.BFS = function(v) {
        var color = initializeColor(),
            queue = new Queue();
            var dis={},
                pre={};
        queue.enqueue(v);
        for(var i=0;i<vertices.length;i++){
            dis.vertices[i]=0;
            pre.vertices[i]=null;
        }
        while (!queue.isEmpt()) {
            var u = queue.dequeue,
                neighbors = adjList.get(u);
            color.u = 'grey'; //访问顶点（发现）
            for (var j = 0; j < nejghbors.length; j++) { //将相邻顶点访问一遍并存入队列（探索）
                var w = nejghbors[j];
                if (color.w === 'white') {
                    color.w = 'grey'; //访问相邻链接的顶点
                    dis.w=dis.u+1;
                    pre.w=u;
                    queue.enqueue(w); //存入队列
                }
            }
            color.u = 'black'; //探索完毕
            return {
                distance:dis,
                predecessors:pre
            };
        }
    };
}
