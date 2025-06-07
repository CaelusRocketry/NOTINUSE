<template>
    <div id="root">
        <div class="row">
            <div class="column">
                <h3>
                    <b>Sensors</b>
                </h3>
            </div>
        </div>
        <div class="row">
            <div class="column column-33">
                Temperature:
                <code>{{ temp.toFixed(2) }} K</code>
            </div>
            <div class="column column-33">
                Altitude:
                <code>{{ altitude.toFixed(1) }} m</code>
            </div>
            <div class="column column-33">
                Flow Rate:
                <code>{{ flowRate.toFixed(3) }} kg/s</code>
            </div>
        </div>
        <div class="row">
            <div class="column column-33">
                Pressure:
                <code>{{ pressure.toFixed(3) }} MPa</code>
            </div>
        </div>
    </div>
</template>

<script>
export default {
    name: "PaneSensors",
    methods: {
        updateTemp() {
            let vm = this;
            setInterval(function() {
                let delta = Math.random() * 20 - 10; // -10 to 10
                vm.$store.state.temp += delta;
            }, 100);
        },
        updateAltitude() {
            let vm = this;
            setInterval(function() {
                let delta = Math.random() * 10; // 0 to 10
                vm.$store.state.altitude += delta;
            }, 100);
        },
        updateFlowRate() {
            let vm = this;
            setInterval(function() {
                let delta = Math.random() * 0.01 - 0.005; // -0.005 to 0.005
                vm.$store.state.flowRate += delta;
            }, 100);
        },
        updatePressure() {
            let vm = this;
            setInterval(function() {
                let delta = Math.random() * 0.01 - 0.005; // -5 to 5
                vm.$store.state.pressure += delta;
            }, 100);
        }
    },
    computed: {
        temp() {
            return this.$store.state.temp;
        },
        altitude() {
            return this.$store.state.altitude;
        },
        flowRate() {
            return this.$store.state.flowRate;
        },
        pressure() {
            return this.$store.state.pressure;
        }
    },
    created() {
        this.updateTemp();
        this.updateAltitude();
        this.updateFlowRate();
        this.updatePressure();
    }
};
</script>

<style scoped>
#root {
    height: 25vh;

    padding: 10px;
    font-size: 1.2em;
    border: 1px solid #c7cacb;
}
</style>

