<template>
    <div id="root">
        <div class="row">
            <div class="column">
                <div id="graph"></div>
            </div>
        </div>
    </div>
</template>

<script>
import Plotly from "plotly.js-dist";
export default {
    name: "PaneGraph",
    methods: {
        updateData() {
            return this.$store.state.altitude;
        }
    },
    mounted() {
        let vm = this;
        let graphLayout = {
            title: "Graph",
            autosize: false,
            height: window.innerHeight * 0.6,
            width: window.innerWidth * 0.45,
            font: {
                family: "Space Mono, monospace",
                size: "1em"
            },
            xaxis: {
                title: {
                    text: "Time (s)",
                    font: {
                        family: "Karla, sans-serif",
                        size: 18,
                        color: "#0d1321"
                    }
                }
            },
            yaxis: {
                title: {
                    text: "Altitude (m)",
                    font: {
                        family: "Karla, sans-serif",
                        size: 18,
                        color: "#0d1321"
                    }
                }
            },

            plot_bgcolor: "#f3f7f0",
            paper_bgcolor: "#f3f7f0"
        };
        Plotly.plot(
            "graph",
            [
                {
                    y: [].map(vm.updateData),
                    mode: "lines",
                    line: { shape: "spline", color: "#435058" }
                }
            ],
            graphLayout
        );

        var interval = setInterval(function() {
            Plotly.extendTraces(
                "graph",
                {
                    y: [[vm.updateData()]]
                },
                [0]
            );
        }, 1000);
    }
};
</script>

<style scoped>
#root {
    height: 65vh;

    padding: 10px;
    font-size: 1.2em;
    border: 1px solid #c7cacb;
}
</style>

