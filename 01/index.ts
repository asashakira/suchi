
let date = new Date();
let y = date.getFullYear();
let m = date.getMonth();
let d = date.getDate();
document.getElementById("today").innerHTML = `${m}/${d}/${y}`;

const f = x => x*x - 5;
const p = x => Number.parseFloat(x).toFixed(6);

let t = "";
let a = 2, b = 3, e = 0.01;
while (Math.abs(a-b) > e) {
  let m = (a+b) / 2;
  t += `
    <tr>
      <td>${p(a)}</td>
      <td>${p(b)}</td>
      <td>${p(m)}</td>
      <td>${p(Math.abs(a-b))}</td>
      <td>${p(f(a))}</td>
      <td>${p(f(m))}</td>
      <td>${ (f(a)*f(m) > 0 ? '+' : '-') }</td>
    </tr>
  `;
  if (f(a)*f(m) < 0) b = m;
  else a = m;
}
let ans = (a+b)/2;
t += `
  <tr>
    <td>${p(a)}</td>
    <td>${p(b)}</td>
    <td>${p(ans)}</td>
    <td>${p(Math.abs(a-b))}</td>
    <td>${p(f(a))}</td>
    <td>${p(f(ans))}</td>
    <td>${ (f(a)*f(ans) > 0 ? '+' : '-') }</td>
  </tr>
`;

document.getElementById("table").innerHTML += t;
document.getElementById("ans").innerHTML = `ans = ${ans}`;

