/**
 * Created by KICT-17 on 2016-07-19.
 */
let array_test = ['banana','orange','apple','mango','raspberry']

console.log(array_test)
array_test.splice(
    2, //삽입 위치
    2, //삭제 원소 갯수
    'grape','peanut')
console.log(array_test)

array_test.splice(2,1)
console.log(array_test)