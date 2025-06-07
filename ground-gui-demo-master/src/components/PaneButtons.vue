<template>
    <div id="root">
        <div class="row">
            <div class="column">
                <h3>
                    <b>Administrative</b>
                </h3>
            </div>
            <div class="column-50">
                <a class="button" @click="emptyTanksWarn = !emptyTanksWarn">Empty Fuel Tanks</a>
            </div>
            <div class="column">
                <p v-if="emptyTanksWarn">Are you sure you want to empty the fuel tanks?</p>
            </div>
            <div class="column-50">
                <a class="button" @click="abortWarn = !abortWarn">Abort</a>
            </div>
            <div class="column">
                <p v-if="abortWarn">Are you sure you want to abort the mission?</p>
            </div>
        </div>
    </div>
</template>

<script>
export default {
    name: "PaneButtons",
    data() {
        return {
            emptyTanksWarn: false,
            abortWarn: false
        };
    }
};
</script>

<style scoped>
#root {
    height: 10vh;

    padding: 10px;
    font-size: 1em;
    border: 1px solid #c7cacb;
}
a {
    font-size: 1em;
    height: auto;
    background-color: #435058;
    transition: 0.5s all;
    margin-right: 3px;
    margin-top: 5px;
}
a:hover {
    background-color: #f72c25;
}
</style>

