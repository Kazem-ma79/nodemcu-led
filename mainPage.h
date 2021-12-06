String webPage = R"=====(
  <!DOCTYPE html>
  <html lang="en">
  <head>
      <meta charset="UTF-8">
      <meta http-equiv="X-UA-Compatible" content="IE=Edge">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Dashboard</title>
      <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
      <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/@simonwep/pickr/dist/themes/classic.min.css" />
      <link rel="stylesheet" href="https://arduino.s3.ir-thr-at1.arvanstorage.com/fan.min.css" />
      <link rel="stylesheet" href="https://arduino.s3.ir-thr-at1.arvanstorage.com/style.min.css">
      <style id="fanBorderStyle">
          .wings.work {
              box-shadow: 0 0 .5rem #fff, inset 0 0 .5rem #fff, 0 0 2rem #08f, inset 0 0 2rem #08f, 0 0 4rem #08f, inset 0 0 4rem #08f;
          }
      </style>
  </head>
  <body>
      <div class="container">
          <div class="pt-4 pb-1 my-auto rounded card col-sm-10 col-md-5 bg-dark">
              <div class="svg text-light">
                  <img class="mb-2 wings off col-3 col-md-5" src="https://arduino.s3.ir-thr-at1.arvanstorage.com/fan.png" alt="Fan">
                  <label for="fanSpeed" class="form-label">Speed Control</label>
                  <!--
                  <span id="speedValue">128</span>
                  <input type="range" class="form-range" id="fanSpeed" value="128" min="0" max="255">
                  !-->
              </div>
              <div class="color-container">
                  <input type="text" class="clr" value="rgb(255, 0, 0)">
              </div>
          </div>
      </div>
      <script src="https://cdn.jsdelivr.net/npm/@simonwep/pickr/dist/pickr.min.js"></script>
      <script>var arduino = "http://{IP_ADDRESS}";</script>
      <script src="https://arduino.s3.ir-thr-at1.arvanstorage.com/script.js"></script>
  </body>
  </html>
)=====";
