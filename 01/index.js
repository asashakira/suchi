var date = new Date();
var y = date.getFullYear();
var m = date.getMonth();
var d = date.getDate();
document.getElementById("today").innerHTML = m + "/" + d + "/" + y;
var f = function (x) { return x * x - 5; };
var p = function (x) { return Number.parseFloat(x).toFixed(6); };
var t = "";
var a = 2, b = 3, e = 0.01;
while (Math.abs(a - b) > e) {
    var m_1 = (a + b) / 2;
    t += "\n    <tr>\n      <td>" + p(a) + "</td>\n      <td>" + p(b) + "</td>\n      <td>" + p(m_1) + "</td>\n      <td>" + p(Math.abs(a - b)) + "</td>\n      <td>" + p(f(a)) + "</td>\n      <td>" + p(f(m_1)) + "</td>\n      <td>" + (f(a) * f(m_1) > 0 ? '+' : '-') + "</td>\n    </tr>\n  ";
    if (f(a) * f(m_1) < 0)
        b = m_1;
    else
        a = m_1;
}
var ans = (a + b) / 2;
t += "\n  <tr>\n    <td>" + p(a) + "</td>\n    <td>" + p(b) + "</td>\n    <td>" + p(ans) + "</td>\n    <td>" + p(Math.abs(a - b)) + "</td>\n    <td>" + p(f(a)) + "</td>\n    <td>" + p(f(ans)) + "</td>\n    <td>" + (f(a) * f(ans) > 0 ? '+' : '-') + "</td>\n  </tr>\n";
document.getElementById("table").innerHTML += t;
document.getElementById("ans").innerHTML = "ans = " + ans;
