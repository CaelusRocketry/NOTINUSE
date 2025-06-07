import Vue from "vue";
import Vuex from "vuex";
import App from "./App.vue";

import "milligram/dist/milligram.min.css";

Vue.config.productionTip = false;
Vue.use(Vuex);

function initialState() {
    return {
        temp: 2750,
        altitude: 1,
        flowRate: 0.9,
        pressure: 2.2
    };
}

const store = new Vuex.Store({
    state: initialState,
    mutations: {
        reset(state) {
            // Acquire initial state
            const s = initialState();
            Object.keys(s).forEach(key => {
                state[key] = s[key];
            });
        }
    }
});

new Vue({
    store,
    render: h => h(App)
}).$mount("#app");
