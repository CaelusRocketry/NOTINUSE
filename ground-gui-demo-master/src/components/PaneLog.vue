<template>
    <div id="root">
        <div class="row">
            <div class="column">
                <h3>
                    <b>Mission Log</b>
                </h3>
            </div>
        </div>
        <div class="row">
            <div class="column" v-if="clock > 40">
                <p>
                    <code>T+40s:</code>
                    {{map.get(40)}}
                </p>
            </div>
        </div>
        <div class="row">
            <div class="column" v-if="clock > 20">
                <p>
                    <code>T+20s:</code>
                    {{map.get(20)}}
                </p>
            </div>
        </div>
        <div class="row">
            <div class="column" v-if="clock > 10">
                <p>
                    <code>T+10s:</code>
                    {{map.get(10)}}
                </p>
            </div>
        </div>
        <div class="row">
            <div class="column" v-if="clock > 0">
                <p>
                    <code>T+0s:</code>
                    {{map.get(0)}}
                </p>
            </div>
        </div>
        <div class="row">
            <div class="column" v-if="clock > -2">
                <p>
                    <code>T-2s:</code>
                    {{map.get(-2)}}
                </p>
            </div>
        </div>
    </div>
</template>

<script>
export default {
    name: "PaneLog",
    data() {
        return {
            clock: -1,
            map: new Map()
        };
    },
    methods: {
        startClock() {
            let vm = this;
            setInterval(function() {
                vm.clock += 1;
            }, 1000);
        }
    },
    created() {
        this.startClock();

        this.map.set(-2, "INFO: Primary engine start");
        this.map.set(0, "INFO: Liftoff");
        this.map.set(10, "ERR: Fuel chamber pressure exceeded bounds");
        this.map.set(20, "INFO: Fuel chamber pressure corrected");
        this.map.set(40, "WARN: Combustion chamber pressure past warn bounds");
    }
};
</script>

<style scoped>
#root {
    height: 37vh;

    padding: 10px;
    font-size: 1.2em;
    border: 1px solid #c7cacb;
    overflow: scroll;
}
</style>

