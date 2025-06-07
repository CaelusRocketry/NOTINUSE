<template>
    <div id="app">
        <div class="row">
            <div class="column">
                <TheHeader/>
            </div>
        </div>
        <div class="row">
            <div class="column column-50">
                <div class="row">
                    <div class="column buffer-bottom">
                        <PaneSensors/>
                    </div>
                </div>
                <div class="row">
                    <div class="column">
                        <PaneLog/>
                    </div>
                </div>
            </div>
            <div class="column column-50 buffer-bottom">
                <PaneGraph/>
            </div>
        </div>
        <div class="row">
            <div class="column">
                <PaneButtons/>
            </div>
        </div>
        <div class="row">
            <div class="column">
                <TheFooter/>
            </div>
        </div>
    </div>
</template>

<script>
import TheHeader from "./components/TheHeader.vue";
import PaneSensors from "./components/PaneSensors.vue";
import PaneGraph from "./components/PaneGraph.vue";
import PaneButtons from "./components/PaneButtons.vue";
import PaneLog from "./components/PaneLog.vue";
import TheFooter from "./components/TheFooter.vue";

export default {
    name: "app",
    components: {
        TheHeader,
        PaneSensors,
        PaneGraph,
        PaneButtons,
        PaneLog,
        TheFooter
    }
};
</script>

<style>
@font-face {
    font-family: "Karla";
    src: url("~@/assets/ttf/Karla-Regular.ttf");
}
@font-face {
    font-family: "Space Mono";
    src: url("~@/assets/ttf/SpaceMono-Regular.ttf");
}
html,
body {
    color: #0d1321 !important;
    background-color: #f3f7f0;
    overflow-x: hidden;
    font-family: "Karla", Helvetica, Arial, sans-serif !important;
    -webkit-font-smoothing: antialiased;
    -moz-osx-font-smoothing: grayscale;
}

#app {
    overflow: hidden;
}

code,
pre {
    font-family: "Space Mono";
}

.align-left {
    text-align: left;
}
.align-center {
    text-align: center;
}
.align-right {
    text-align: right;
}
.buffer-bottom {
    margin-bottom: 3vh !important;
}
</style>
