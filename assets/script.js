let wingsImg = document.querySelector(".wings");

function hexToRgb(hex) {
    let result = /^#?([a-f\d]{2})([a-f\d]{2})([a-f\d]{2})$/i.exec(hex);
    return result ? {
        r: parseInt(result[1], 16),
        g: parseInt(result[2], 16),
        b: parseInt(result[3], 16)
    } : null;
}

function parseColor(input) {
    let color = input.toHEXA();
    return hexToRgb(color);
}

document.getElementsByClassName('wings')[0].addEventListener('click', function(e) {
    if (e.target.classList.contains('wings')) {
        let request = new XMLHttpRequest();
        request.onload = function() {
            let ledState = JSON.parse(this.responseText).state;
            if (ledState) {
                wingsImg.classList.add("work");
            } else {
                wingsImg.classList.remove("work");
            }
        }
        request.open("GET", arduino + "/fan");
        request.send();
    }
});
/*
document.getElementById('fanSpeed').addEventListener('change', function() {
    let speed = this.value;
    document.getElementById('speedValue').innerHTML = speed;
    if (speed > 0) {
        let time = 251 - speed;
        wingsImg.style.animationDuration = 251 - speed + "ms";
    } else {
        wingsImg.style.animationDuration = "0s";
    }
    let request = new XMLHttpRequest();
    request.open("POST", arduino + "/fan?speed=" + speed);
    request.send();
});*/

window.onload = function() {
    let buttons = document.querySelectorAll('input[type="button"]');
    [].forEach.call(buttons, btn => {
        btn.classList.add('btn');
    });
}

const pickr = Pickr.create({
    el: '.clr',
    theme: 'classic',
    container: '.color-container',
    lockOpacity: true,
    showAlways: true,
    sliders: 'v',
    comparison: false,
    defaultRepresentation: 'RGB',
    appClass: 'color-picker shadow',
    autoPosition: true,

    swatches: [
        '#FF191B',
        '#FF5319',
        '#FF6A5E',
        '#FF926B',
        '#F3F62F',
        '#288F00',
        '#3CD45F',
        '#47E3C6',
        '#44C5DE',
        '#289AE3',
        '#122B9C',
        '#6C6CD4',
        '#5D2AE3',
        '#9025DE',
        '#BE11E3'
    ],

    components: {
        palette: true,
        preview: false,
        opacity: false,
        hue: true,

        interaction: {
            cancel: true,
            save: true,
            clear: true
        }
    },
    i18n: {
        'btn:save': 'SET',
        'btn:cancel': 'OFF',
        'btn:clear': 'FADE',

        'aria:btn:save': 'set and close',
        'aria:btn:cancel': 'turn off and close',
        'aria:btn:clear': 'fade and close'
    }
});

pickr.on('save', (color, instance) => {
    let clr = parseColor(color);
    let request = new XMLHttpRequest();
    request.open("POST", arduino + "/color");
    request.setRequestHeader("Content-Type", "application/json; charset=UTF-8");
    request.send(JSON.stringify({
        "color": {
            "red": clr.r,
            "green": clr.g,
            "blue": clr.b
        }
    }));
}).on('cancel', (instance) => {
    let request = new XMLHttpRequest();
    request.open("GET", arduino + "/off");
    request.send();
}).on('clear', (instance) => {
    let request = new XMLHttpRequest();
    request.open("GET", arduino + "/lightup");
    request.send();
}).on('change', (color) => {
    let hex = color.toHEXA();
    document.getElementById('fanBorderStyle').innerHTML = `.wings.work {box-shadow: 0 0 .5rem #fff, inset 0 0 .5rem #fff, 0 0 2rem ${hex}, inset 0 0 2rem ${hex}, 0 0 4rem ${hex}, inset 0 0 4rem ${hex}; }`;
});