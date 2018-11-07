let base_url = `https://jsonmock.hackerrank.com/api/countries/search`;

let https = require('https');

function getTotalPages(s) {
  let url = `${base_url}?name=${s}`;

  return new Promise((resolve, reject) => {
    https.get(url, res => {

      let response = "";

      res.on('data', chunk => {
        response += chunk;
      });

      res.on('end', _ => {
        // First request to determine the pagination
        resolve(JSON.parse(response).total_pages);
      });
    }).on('error', err => reject(err));
  })
}

function getCountriesPerPage(s, page) {
  let url = `${base_url}?name=${s}&page=${page}`;

  return new Promise((resolve, reject) => {
    https.get(url, res => {
      let response = "";
      res.on('data', chunk => {
        response += chunk;
      })

      res.on('end', _ => {
        resolve(JSON.parse(response).data);
      });
    }).on('error', err => reject(err))
  });
}

function getCountries(s, p) {
  getTotalPages(s).then(total_pages => {
    let current_page = 1;
    let q = [];
    while (current_page <= total_pages) {
      q.push(getCountriesPerPage(s, current_page));
      current_page++;
    }
    Promise.all(q)
      .then(countries_pages => {
        let result = [];
        let count = 0;

        for (let countries of countries_pages) {
          //console.log(countries);
          result = (countries.filter(function (e) {
            return e.population > p;
          }));
          count += result.length;
          // console.log(count);
          // console.log("--------------------------");
        }
        console.log(count);
      })
      .catch(err => console.log(err));

  })
    .catch(err => console.log(err))
}

getCountries("c", 3000000);