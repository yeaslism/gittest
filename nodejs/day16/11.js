/**
 * Created by KICT-17 on 2016-07-19.
 */

let array_test = [
{
    name : 'seok',
    hp: 52
},
{
    name : 'mongu',
    hp: 27
},
{
    name : 'trol',
    hp: 47
}


]

console.log(array_test)

array_test.sort( (left,right)=> {
    return left.hp - right.hp;
})

console.log('============================')
console.log(array_test)